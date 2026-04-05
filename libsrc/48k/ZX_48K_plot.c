#include "zx_48k.h"

void ZX_48K_plot(uint8_t x, uint8_t y) {
	x; // A reg
	y; // L reg

  __asm
    ld	c, a
    ld	b, l
    call 0x22E5
  __endasm;
}
