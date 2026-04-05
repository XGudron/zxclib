#include "zx_evo_ers.h"

void ZX_EVO_devmanager_volume_reinit(void) {
	// TODO узнать параметры функции и её результат

	__asm
	RST 8
	.db 0x50
	.db 0x08
	__endasm;
}
