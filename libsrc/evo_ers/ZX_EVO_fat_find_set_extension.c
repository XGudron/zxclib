#include "zx_evo_ers.h"

void ZX_EVO_fat_find_set_extension(uint8_t type, uint8_t *buffer) {
	type;   // A reg
	buffer; // DE reg

	__asm
	ld h, d
	ld l, e
	RST 8
	.db 0x51
	.db 0x07
	__endasm;
}
