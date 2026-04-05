#include "zx_evo_ers.h"

void ZX_EVO_fat_open_file(void) {
	__asm
	RST 8
	.db 0x51
	.db 0x08
	__endasm;
}
