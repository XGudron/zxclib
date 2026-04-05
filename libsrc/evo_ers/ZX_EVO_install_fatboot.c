#include "zx_evo_ers.h"

void ZX_EVO_install_fatboot(uint8_t *buffer) {
	buffer; // HL reg

	__asm
	RST 8
	.db 0x54
	__endasm;
}
