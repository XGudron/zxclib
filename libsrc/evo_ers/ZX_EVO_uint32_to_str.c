#include "zx_evo_ers.h"

void ZX_EVO_uint32_to_str(char *str, uint32_t dec) {
	str; // HL reg
	dec; // in stack

	__asm
	ld b, 7(ix)
	ld c, 6(ix)
	ld d, 5(ix)
	ld e, 4(ix)
	RST 8
	.db 0x4C
	.db 0x04
	__endasm;
}
