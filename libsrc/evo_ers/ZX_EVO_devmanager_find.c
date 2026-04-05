#include "zx_evo_ers.h"

void ZX_EVO_devmanager_find(void) {
	__asm
	RST 8
	.db 0x50
	.db 0x00
	__endasm;

	// TODO implement return
}
