#include "zx_48k.h"

uint16_t ZX_48K_keyscan(void) __naked {
  __asm
    push hl
    call 0x028E
    pop hl
    ret ; output in DE
  __endasm;
}
