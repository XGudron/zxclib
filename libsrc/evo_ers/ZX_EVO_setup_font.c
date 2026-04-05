#include "zx_evo_ers.h"

void ZX_EVO_setup_font(uint8_t type, uint8_t *font_addr) {
	type;      // A reg
	font_addr; // DE reg

	__asm
	ld h, d
	ld l, e
	RST 8
	.db 0x57
	__endasm;
}
