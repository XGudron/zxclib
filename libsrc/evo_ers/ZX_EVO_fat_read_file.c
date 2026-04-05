#include "zx_evo_ers.h"

uint8_t ZX_EVO_fat_read_file(uint8_t sector_count, uint8_t *buffer) {
	sector_count; // A reg
	buffer;       // DE reg

	__asm
	ld h, d
	ld l, e
	RST 8
	.db 0x51
	.db 0x09
	ld a, c
	ret
	__endasm;

	return 0;
}
