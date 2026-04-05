#include "zx_evo_ers.h"

void ZX_EVO_mount_virtual_drive_bits(void) {
	// TODO узнать параметры функции и её результат

	__asm
	RST 8
	.db 0x53
	.db 0x09
	__endasm;
}
