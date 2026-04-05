#include <zx_trdos.h>

void ZX_TRDOS_set_bottom_side(void) {
	__asm
		ld c, #0x17
		call 0x3D13
	__endasm;
}
