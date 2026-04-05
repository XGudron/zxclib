#include "zx_evo_ers.h"

void ZX_EVO_fat_init_cluster(void) {
	__asm
	RST 8
	.db 0x51
	.db 0x0A
	__endasm;
}
