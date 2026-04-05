#include "zx_evo_ers.h"

uint32_t ZX_EVO_divide32_remainder(uint32_t a, uint32_t b) {
	a; // HLDE reg
	b; // in stack

	__asm
	ld b, h
	ld c, l
	exx
	ld b, 7(ix)
	ld c, 6(ix)
	ld d, 5(ix)
	ld e, 4(ix)
	exx
	RST 8
	.db 0x4C
	.db 0x02
	exx
	push de
	push bc
	exx
	pop bc
	pop de
	ld h, b
	ld l, c
	pop ix
	ret
	__endasm;

	return 0;
}
