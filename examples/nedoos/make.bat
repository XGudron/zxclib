SET Z80_FLAGS=--allow-undocumented-instructions --no-std-crt0
SET OPTIMIZATION_FLAGS=--opt-code-speed --peep-return --max-allocs-per-node 200000
SET CODE_FLAGS=-mz80
SET GENERAL_FLAGS=--std c23 --Werror -I../../include/
SET LIBRARY_PATH= -l ../../libsrc/zxclib.lib -l ../../libsrc/nedoos.lib
SET LINKER_FLAGS=--code-loc 0x0110 --data-loc 0x2000 %LIBRARY_PATH%
SET BUILD_DIR=build
SET EXECUTABLE_NAME=example

SET BUILD_OPTS=-o %BUILD_DIR%\%EXECUTABLE_NAME%.ihx

mkdir %BUILD_DIR%

sdasz80 -o -g %BUILD_DIR%\crt0.rel ../../libsrc/crt0_nedoos.asm
@IF %ERRORLEVEL% EQU 1 GOTO ERR

sdcc %CODE_FLAGS% %GENERAL_FLAGS% %Z80_FLAGS% %OPTIMIZATION_FLAGS% %LINKER_FLAGS% %BUILD_DIR%\crt0.rel main.c %BUILD_OPTS%
@IF %ERRORLEVEL% EQU 1 GOTO ERR

makebin -yo A -o 0x0100 -p %BUILD_DIR%\%EXECUTABLE_NAME%.ihx %EXECUTABLE_NAME%.com
@IF %ERRORLEVEL% EQU 1 GOTO ERR

del %EXECUTABLE_NAME%.scl

"../../../pcsoft/trdtool/trdtool.exe" # %EXECUTABLE_NAME%.scl
@IF %ERRORLEVEL% EQU 1 GOTO ERR

"../../../pcsoft/trdtool/trdtool.exe" + %EXECUTABLE_NAME%.scl %EXECUTABLE_NAME%.com
@IF %ERRORLEVEL% EQU 1 GOTO ERR

@ECHO.
@ECHO Compiled successfully !!!

"../../../pcsoft/emul_nedoos/emul.exe" %EXECUTABLE_NAME%.scl
GOTO END

:ERR
PAUSE

:END