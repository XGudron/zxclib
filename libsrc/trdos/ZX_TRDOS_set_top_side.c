#include <zx_trdos.h>

void ZX_TRDOS_set_top_side(void) {
	__asm
		ld c, #0x16
		call 0x3D13
	__endasm;
}
