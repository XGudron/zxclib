#include "zx_evo_ers.h"

void ZX_EVO_devmanager_set_sector(void) {
	// TODO узнать параметры функции и её результат

	__asm
	RST 8
	.db 0x50
	.db 0x09
	__endasm;
}
