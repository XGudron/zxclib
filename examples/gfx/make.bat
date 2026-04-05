SET Z80_FLAGS=--allow-undocumented-instructions --no-std-crt0 --reserve-regs-iy --max-allocs-per-node 2000000
SET OPTIMIZATION_FLAGS=--opt-code-speed --peep-return
SET CODE_FLAGS=-mz80
SET GENERAL_FLAGS=--std c23 --Werror -I../../include/
SET LIBRARY_PATH=../../libsrc/zxclib.lib
SET LINKER_FLAGS=--code-loc 0x8010 --data-loc 0xB000 -l %LIBRARY_PATH%
SET BUILD_DIR=build
SET EXECUTABLE_NAME=gfx
SET BUILD_OPTS=-o %BUILD_DIR%\%EXECUTABLE_NAME%.ihx

mkdir %BUILD_DIR%

sdasz80 -o -g %BUILD_DIR%\crt0.rel ../../libsrc/crt0_48k.asm
@IF %ERRORLEVEL% EQU 1 GOTO ERR

sdcc %CODE_FLAGS% %GENERAL_FLAGS% %Z80_FLAGS% %OPTIMIZATION_FLAGS% %LINKER_FLAGS% %BUILD_DIR%\crt0.rel main.c %BUILD_OPTS%
@IF %ERRORLEVEL% EQU 1 GOTO ERR

makebin -yo A -o 0x8000 -p %BUILD_DIR%\%EXECUTABLE_NAME%.ihx %EXECUTABLE_NAME%.bin
@IF %ERRORLEVEL% EQU 1 GOTO ERR

z88dk-appmake +zx -b %EXECUTABLE_NAME%.bin -o %EXECUTABLE_NAME%.tap --org 0x8000 --clean --autoexec --blockname "%EXECUTABLE_NAME%"
@IF %ERRORLEVEL% EQU 1 GOTO ERR

@ECHO.
@ECHO Compiled successfully !!!

"../../../pcsoft/ZEsarUX_windows-13.0/zesarux.exe" --machine 48k --tape %EXECUTABLE_NAME%.tap
GOTO END

:ERR
PAUSE

:END