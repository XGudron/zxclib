#include "zx_evo_ers.h"

void ZX_EVO_fat_enter_directory(void) {
	__asm
	RST 8
	.db 0x51
	.db 0x02
	__endasm;
}
