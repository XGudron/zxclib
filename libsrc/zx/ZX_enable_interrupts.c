#include "zx_48k.h"

void ZX_enable_interrupts(void) {
    __asm
        ei
    __endasm;
}
