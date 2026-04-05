#include "zx_evo_ers.h"

void ZX_EVO_fat_go_root(void) {
	__asm
	RST 8
	.db 0x51
	.db 0x0C
	__endasm;
}
