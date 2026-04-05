#include "zx_evo_ers.h"

void ZX_EVO_uint8_to_str(char *str, uint8_t dec) {
	str; // HL reg
	dec; // In stack

	__asm
	ld e, 4(ix)
	RST 8
	.db 0x4C
	.db 0x06
	__endasm;
}
