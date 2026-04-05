#include "zx_evo_ers.h"

void ZX_EVO_setup_palette(uint8_t *pallete_addr) {
	pallete_addr; // HL reg

	__asm
	ld a, #1
	RST 8
	.db 0x56
	__endasm;
}
