#include "zx_evo_ers.h"

void ZX_EVO_cmos_init(void) {
	__asm
	RST 8
	.db 0x55
	.db 0x00
	__endasm;
}
