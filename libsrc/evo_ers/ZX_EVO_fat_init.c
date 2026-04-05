#include "zx_evo_ers.h"

void ZX_EVO_fat_init(void) {
	__asm
	RST 8
	.db 0x51
	.db 0x00
	__endasm;
}
