#include "zx_evo_ers.h"

uint8_t ZX_EVO_cmos_read(uint8_t addr) {
	addr; // A reg

	__asm
	ld h, a;
	RST 8
	.db 0x55
	.db 0x01
	ret
	__endasm;

	return 0;
}
