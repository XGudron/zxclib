#include "zx_evo_ers.h"

void ZX_EVO_fat_get_path(uint8_t *buffer) {
	buffer; // HL reg

	__asm
	RST 8
	.db 0x51
	.db 0x03
	__endasm;
}
