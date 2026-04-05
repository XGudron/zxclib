#include <zx_trdos.h>

void ZX_TRDOS_read_system_sector(void) {
	__asm
		ld c, #0x18
		call 0x3D13
	__endasm;
}
