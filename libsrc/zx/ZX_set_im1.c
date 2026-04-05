#include "zx_48k.h"

void ZX_set_im1(void) {
    __asm
        di
        im 1
        ei
    __endasm;
}
