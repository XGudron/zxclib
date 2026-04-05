SET Z80_FLAGS=--allow-undocumented-instructions --no-std-crt0 --reserve-regs-iy
SET OPTIMIZATION_FLAGS=--opt-code-speed --peep-return
SET CODE_FLAGS=-mz80
SET GENERAL_FLAGS=--std c23 --Werror -I../../include/
SET LIBRARY_PATH=../../libsrc/zxclib.lib
SET LINKER_FLAGS=--code-loc 0x6010 --data-loc 0xA000 -Wl "-b _BANK0=0x0C000" -Wl "-b _BANK1=0x1C000" -l %LIBRARY_PATH%
SET BUILD_DIR=build
SET EXECUTABLE_NAME=evo-baseconf

SET BUILD_OPTS=-o %BUILD_DIR%\%EXECUTABLE_NAME%.ihx

mkdir %BUILD_DIR%

sdasz80 -o -g %BUILD_DIR%\crt0.rel ../../libsrc/crt0_evo.asm
@IF %ERRORLEVEL% EQU 1 GOTO ERR

sdcc %CODE_FLAGS% %GENERAL_FLAGS% %Z80_FLAGS% %OPTIMIZATION_FLAGS% %LINKER_FLAGS% -c bank0.c -o %BUILD_DIR%\
@IF %ERRORLEVEL% EQU 1 GOTO ERR

sdcc %CODE_FLAGS% %GENERAL_FLAGS% %Z80_FLAGS% %OPTIMIZATION_FLAGS% %LINKER_FLAGS% -c bank1.c -o %BUILD_DIR%\
@IF %ERRORLEVEL% EQU 1 GOTO ERR

sdcc %CODE_FLAGS% %GENERAL_FLAGS% %Z80_FLAGS% %OPTIMIZATION_FLAGS% %LINKER_FLAGS% %BUILD_DIR%\crt0.rel %BUILD_DIR%\bank0.rel %BUILD_DIR%\bank1.rel main.c %BUILD_OPTS%
@IF %ERRORLEVEL% EQU 1 GOTO ERR

makebin -yo A -o 0x6000 -p %BUILD_DIR%\%EXECUTABLE_NAME%.ihx code.com
@IF %ERRORLEVEL% EQU 1 GOTO ERR
fsutil file seteof code.com 0x6000
@IF %ERRORLEVEL% EQU 1 GOTO ERR

makebin -yo A -o 0xC000 -p %BUILD_DIR%\%EXECUTABLE_NAME%.ihx bank0.com
@IF %ERRORLEVEL% EQU 1 GOTO ERR
fsutil file seteof bank0.com 0x4000
@IF %ERRORLEVEL% EQU 1 GOTO ERR

makebin -yo A -o 0x1C000 -p %BUILD_DIR%\%EXECUTABLE_NAME%.ihx bank1.com
@IF %ERRORLEVEL% EQU 1 GOTO ERR
fsutil file seteof bank1.com 0x4000
@IF %ERRORLEVEL% EQU 1 GOTO ERR

"../../../pcsoft/bas2hob/bas2hob.exe" -a -sBOOT loader.bas

del %EXECUTABLE_NAME%.trd
del %EXECUTABLE_NAME%.scl

"../../../pcsoft/trdtool/trdtool.exe" # %EXECUTABLE_NAME%.scl
@IF %ERRORLEVEL% EQU 1 GOTO ERR

"../../../pcsoft/trdtool/trdtool.exe" + %EXECUTABLE_NAME%.scl loader.$B
@IF %ERRORLEVEL% EQU 1 GOTO ERR

"../../../pcsoft/trdtool/trdtool.exe" + %EXECUTABLE_NAME%.scl code.com
@IF %ERRORLEVEL% EQU 1 GOTO ERR

"../../../pcsoft/trdtool/trdtool.exe" + %EXECUTABLE_NAME%.scl bank0.com
@IF %ERRORLEVEL% EQU 1 GOTO ERR

"../../../pcsoft/trdtool/trdtool.exe" + %EXECUTABLE_NAME%.scl bank1.com
@IF %ERRORLEVEL% EQU 1 GOTO ERR

@ECHO.
@ECHO Compiled successfully !!!

"../../../pcsoft/emul_nedoos/emul.exe" %EXECUTABLE_NAME%.scl
GOTO END

:ERR
PAUSE

:END