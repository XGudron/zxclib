#include "zx_evo_ers.h"

void ZX_EVO_mount_ramdisk(void) {
	// TODO узнать параметры функции и её результат

	__asm
	RST 8
	.db 0x53
	.db 0x0A
	__endasm;
}
