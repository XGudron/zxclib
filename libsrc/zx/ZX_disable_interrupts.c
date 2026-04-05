#include "zx_48k.h"

void ZX_disable_interrupts(void) {
    __asm
        di
    __endasm;
}
