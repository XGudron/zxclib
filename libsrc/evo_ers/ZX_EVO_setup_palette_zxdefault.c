#include "zx_evo_ers.h"

void ZX_EVO_setup_palette_zxdefault(void) {
	__asm
	ld a, #0
	RST 8
	.db 0x56
	__endasm;
}
