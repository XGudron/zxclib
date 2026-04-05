#include <zx_trdos.h>

void ZX_TRDOS_reset(void) {
	__asm
		ld c, #0x00
		call 0x3D13
	__endasm;
}
