#include "zx_evo_ers.h"

void ZX_EVO_mount_find(void) {
	__asm
	RST 8
	.db 0x53
	.db 0x02
	__endasm;
}
