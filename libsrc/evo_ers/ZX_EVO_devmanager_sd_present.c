#include "zx_evo_ers.h"

void ZX_EVO_devmanager_sd_present(void) {
	// TODO узнать параметры функции и её результат

	__asm
	RST 8
	.db 0x50
	.db 0x06
	__endasm;
}
