SET Z80_FLAGS=--allow-undocumented-instructions --no-std-crt0 --reserve-regs-iy --max-allocs-per-node 2000000
SET OPTIMIZATION_FLAGS=--opt-code-speed --peep-return
SET CODE_FLAGS=-mz80
SET GENERAL_FLAGS=--std c23 --Werror -I../../include/
SET LIBRARY_PATH=../../libsrc/zxclib.lib
SET LINKER_FLAGS=--code-loc 0x8010 --data-loc 0xA000 -Wl "-b _BANK0=0x0C000" -Wl "-b _BANK1=0x1C000" -l %LIBRARY_PATH%
SET BUILD_DIR=build
SET EXECUTABLE_NAME=128k-bank
SET BUILD_OPTS=-o %BUILD_DIR%\%EXECUTABLE_NAME%.ihx

mkdir %BUILD_DIR%

sdasz80 -o -g %BUILD_DIR%\crt0.rel ../../libsrc/crt0_128k.asm
@IF %ERRORLEVEL% EQU 1 GOTO ERR

sdcc %CODE_FLAGS% %GENERAL_FLAGS% %Z80_FLAGS% %OPTIMIZATION_FLAGS% %LINKER_FLAGS% -c bank0.c -o %BUILD_DIR%\
@IF %ERRORLEVEL% EQU 1 GOTO ERR

sdcc %CODE_FLAGS% %GENERAL_FLAGS% %Z80_FLAGS% %OPTIMIZATION_FLAGS% %LINKER_FLAGS% -c bank1.c -o %BUILD_DIR%\
@IF %ERRORLEVEL% EQU 1 GOTO ERR

sdcc %CODE_FLAGS% %GENERAL_FLAGS% %Z80_FLAGS% %OPTIMIZATION_FLAGS% %LINKER_FLAGS% %BUILD_DIR%\crt0.rel %BUILD_DIR%\bank0.rel %BUILD_DIR%\bank1.rel main.c %BUILD_OPTS%
@IF %ERRORLEVEL% EQU 1 GOTO ERR

makebin -yo A -o 0x8000 -p %BUILD_DIR%\%EXECUTABLE_NAME%.ihx %EXECUTABLE_NAME%.bin
@IF %ERRORLEVEL% EQU 1 GOTO ERR
fsutil file seteof %EXECUTABLE_NAME%.bin 0x4000
@IF %ERRORLEVEL% EQU 1 GOTO ERR

makebin -yo A -o 0xC000 -p %BUILD_DIR%\%EXECUTABLE_NAME%.ihx bank0.bin
@IF %ERRORLEVEL% EQU 1 GOTO ERR
fsutil file seteof bank0.bin 0x4000
@IF %ERRORLEVEL% EQU 1 GOTO ERR

makebin -yo A -o 0x1C000 -p %BUILD_DIR%\%EXECUTABLE_NAME%.ihx bank1.bin
@IF %ERRORLEVEL% EQU 1 GOTO ERR
fsutil file seteof bank1.bin 0x4000
@IF %ERRORLEVEL% EQU 1 GOTO ERR

z88dk-appmake +zx --noloader -b bank0.bin -o bank0.tap --org 0xC000 --clean --blockname "Bank0"
@IF %ERRORLEVEL% EQU 1 GOTO ERR

z88dk-appmake +zx --noloader -b bank1.bin -o bank1.tap --org 0xC000 --clean --blockname "Bank1"
@IF %ERRORLEVEL% EQU 1 GOTO ERR

z88dk-appmake +zx --noloader -b %EXECUTABLE_NAME%.bin -o %EXECUTABLE_NAME%.tap --org 0x8000 --clean --autoexec --blockname "%EXECUTABLE_NAME%"
@IF %ERRORLEVEL% EQU 1 GOTO ERR

"../../../pcsoft/bas2tap/bas2tap.exe" -a loader.bas loader.tap

copy /b loader.tap + bank0.tap + bank1.tap + %EXECUTABLE_NAME%.tap example.tap
@IF %ERRORLEVEL% EQU 1 GOTO ERR

@ECHO.
@ECHO Compiled successfully !!!

"../../../pcsoft/ZEsarUX_windows-13.0/zesarux.exe" --machine 128k --tape example.tap
GOTO END

:ERR
PAUSE

:END