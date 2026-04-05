#include "zx_evo_ers.h"

void ZX_EVO_mount_load_image(void) {
	__asm
	RST 8
	.db 0x53
	.db 0x05
	__endasm;
}
