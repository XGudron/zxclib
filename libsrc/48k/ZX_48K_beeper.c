#include "zx_48k.h"

void ZX_48K_beeper(uint16_t divisor, uint16_t duration) {
  divisor; // HL reg
  duration; // DE reg
  __asm
    call 0x03B5
  __endasm;
}
