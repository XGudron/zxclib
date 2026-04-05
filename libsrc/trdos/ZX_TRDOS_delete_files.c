#include <zx_trdos.h>

void ZX_TRDOS_delete_files(void) {
	__asm
		ld c, #0x12
		call 0x3D13
	__endasm;
}
