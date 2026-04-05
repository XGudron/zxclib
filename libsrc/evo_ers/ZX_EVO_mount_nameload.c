#include "zx_evo_ers.h"

void ZX_EVO_mount_nameload(uint8_t *buffer) {
	buffer; // HL reg

	__asm
	RST 8
	.db 0x53
	.db 0x07
	__endasm;
}
