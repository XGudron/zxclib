#include "zx_evo_ers.h"

void ZX_EVO_cmos_write(uint8_t addr, uint8_t value) {
	addr; // A reg
	value; // L reg

	__asm
	ld h, a;
	RST 8
	.db 0x55
	.db 0x02
	__endasm;
}
