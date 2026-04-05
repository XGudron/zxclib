#include "zx_evo_ers.h"

uint16_t ZX_EVO_fat_find_by_name(uint8_t *name) {
	name; // HL reg

	__asm
	RST 8
	.db 0x51
	.db 0x05
	ld d, b
	ld e, c
	ret
	__endasm;

	return 0;
}
