#include "zx_evo_ers.h"

uint32_t ZX_EVO_multiply32(uint16_t a, uint32_t b) {
	a; // HL reg
	b; // in stack

	__asm
	ld b, 7(ix)
	ld c, 6(ix)
	ld d, 5(ix)
	ld e, 4(ix)
	RST 8
	.db 0x4C
	.db 0x03
	ld h, b
	ld l, c
	pop ix
	ret
	__endasm;

	return 0;
}
