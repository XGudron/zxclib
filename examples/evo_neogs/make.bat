SET Z80_FLAGS=--allow-undocumented-instructions --no-std-crt0 --reserve-regs-iy
SET OPTIMIZATION_FLAGS=--opt-code-speed --peep-return
SET CODE_FLAGS=-mz80
SET GENERAL_FLAGS=--std c23 --Werror -I../../include/
SET LIBRARY_PATH=../../libsrc/zxclib.lib
SET LINKER_FLAGS=--code-loc 0x6010 --data-loc 0xA000 -l %LIBRARY_PATH%
SET BUILD_DIR=build
SET EXECUTABLE_NAME=evo-neogs

SET BUILD_OPTS=-o %BUILD_DIR%\%EXECUTABLE_NAME%.ihx

mkdir %BUILD_DIR%

sdasz80 -o -g %BUILD_DIR%\crt0.rel ../../libsrc/crt0_evo.asm
@IF %ERRORLEVEL% EQU 1 GOTO ERR

sdcc %CODE_FLAGS% %GENERAL_FLAGS% %Z80_FLAGS% %OPTIMIZATION_FLAGS% %LINKER_FLAGS% %BUILD_DIR%\crt0.rel main.c %BUILD_OPTS%
@IF %ERRORLEVEL% EQU 1 GOTO ERR

makebin -yo A -o 0x6000 -p %BUILD_DIR%\%EXECUTABLE_NAME%.ihx code.com
@IF %ERRORLEVEL% EQU 1 GOTO ERR
fsutil file seteof code.com 0x6000
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

"../../../pcsoft/trdtool/trdtool.exe" + %EXECUTABLE_NAME%.scl mod1.mod
"../../../pcsoft/trdtool/trdtool.exe" + %EXECUTABLE_NAME%.scl mod2.mod
"../../../pcsoft/trdtool/trdtool.exe" + %EXECUTABLE_NAME%.scl mod3.mod
"../../../pcsoft/trdtool/trdtool.exe" + %EXECUTABLE_NAME%.scl mod4.mod
"../../../pcsoft/trdtool/trdtool.exe" + %EXECUTABLE_NAME%.scl mod5.mod
"../../../pcsoft/trdtool/trdtool.exe" + %EXECUTABLE_NAME%.scl mod6.mod
@IF %ERRORLEVEL% EQU 1 GOTO ERR

@ECHO.
@ECHO Compiled successfully !!!

"../../../pcsoft/emul_nedoos/emul.exe" %EXECUTABLE_NAME%.scl
GOTO END

:ERR
PAUSE

:END