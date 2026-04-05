#include "zx_evo_ers.h"

void ZX_EVO_devmanager_call_driver(void) {
	// TODO узнать параметры функции и её результат

	__asm
	RST 8
	.db 0x50
	.db 0x04
	__endasm;
}
