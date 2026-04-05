#include "zx_48k.h"

void ZX_48K_scroll_up(void) {
    __asm
        call 0x0DFE      ; CL-SC-ALL ROM subroutine
    __endasm;
}
