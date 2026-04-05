#include "zx_48k.h"

void ZX_48K_clear_lines(uint8_t rows) {
	rows; // A reg

    __asm
        ld   b, a         ; количество строк в B
        call 0x0E44      ; CL-LINE ROM subroutine
    __endasm;
}
