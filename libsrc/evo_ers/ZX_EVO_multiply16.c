#include "zx_evo_ers.h"

uint32_t ZX_EVO_multiply16(uint16_t a, uint16_t b) {
	a; // HL reg
	b; // DE reg

	__asm
	ld b, h
	ld c, l
	RST 8
	.db 0x4C
	.db 0x01
	ld h, b
	ld l, c
	ret
	__endasm;

	return 0;
}
