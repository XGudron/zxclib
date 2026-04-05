#include "zx_48k.h"

void ZX_48K_recover_IY(void) {
  __asm
    ld   iy, #0x5C3A ; SDCC libs can broke spectrum ROM IY in some cases (printf for example)
  __endasm;
}
