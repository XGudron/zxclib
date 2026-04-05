#include "zx_evo_ers.h"

void ZX_EVO_fat_get_pointer(uint8_t *ptr, uint16_t file_num) {
	ptr;      // HL reg
	file_num; // DE reg

	__asm
	ld b, d
	ld c, e
	RST 8
	.db 0x51
	.db 0x01
	__endasm;
}
