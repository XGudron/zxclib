#include "zx_48k.h"

void ZX_48K_draw_line_step(uint8_t dx, uint8_t dy, int8_t step_x, int8_t step_y) {
    dx; // A reg
    dy; // L reg
    step_x; // in stack
    step_y; // in stack
    
    __asm
        ld b, l ; ABS(Y)
        ld c, a ; ABS(X)
        ld d, 5(ix); SGN(Y)
        ld e, 4(ix) ; SGN(X)
        call 0x24BA      ; DRAW-3 ROM subroutine
    __endasm;
}
