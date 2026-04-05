#include "zx_48k.h"

void ZX_set_im0(void) {
    __asm
        di
        im 0
        ei
    __endasm;
}
