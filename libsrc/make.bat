SET Z80_FLAGS=--allow-undocumented-instructions --no-std-crt0 --reserve-regs-iy
@REM Can use --max-allocs-per-node 2000000 for max optimization (slooowly)
SET OPTIMIZATION_FLAGS=--opt-code-speed --peep-return --max-allocs-per-node 2000000
SET CODE_FLAGS=-mz80
SET GENERAL_FLAGS=--std c23 --Werror -I../include/
SET LINKER_FLAGS=--code-loc 0x8010 --data-loc 0xB000
SET BUILD_DIR=build
SET EXECUTABLE_NAME=zxclib
SET BUILD_OPTS=-c -o %BUILD_DIR%\

del %EXECUTABLE_NAME%.lib

mkdir %BUILD_DIR%

@echo off

for /R %%f in (*.c) do (
    echo Processing file: %%f
    sdcc %CODE_FLAGS% %GENERAL_FLAGS% %Z80_FLAGS% %OPTIMIZATION_FLAGS% %LINKER_FLAGS% %%f %BUILD_OPTS%
    if errorlevel 1 goto ERR

    sdar -rc %EXECUTABLE_NAME%.lib %BUILD_DIR%\%%~nf.rel
    if errorlevel 1 goto ERR
)

@echo on

GOTO END

:ERR
PAUSE

:END