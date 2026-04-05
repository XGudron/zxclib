#include "zx_evo_ers.h"

uint16_t ZX_EVO_divide16(uint16_t a, uint16_t b) {
	a; // HL reg
	b; // DE reg

	__asm
	ld b, h
	ld c, l
	RST 8
	.db 0x4C
	.db 0x00
	ret
	__endasm;

	return 0;
}
