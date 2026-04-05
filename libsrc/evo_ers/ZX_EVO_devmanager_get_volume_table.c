#include "zx_evo_ers.h"

void ZX_EVO_devmanager_get_volume_table(uint8_t *buffer) {
	buffer; // HL reg

	__asm
	RST 8
	.db 0x50
	.db 0x03
	__endasm;
}
