#include "zx_evo_ers.h"

void ZX_EVO_cmos_reset(void) {
	__asm
	RST 8
	.db 0x55
	.db 0x03
	__endasm;
}
