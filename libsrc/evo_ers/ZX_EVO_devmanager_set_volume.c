#include "zx_evo_ers.h"

void ZX_EVO_devmanager_set_volume(uint8_t volume) {
	volume; // A reg

	__asm
	RST 8
	.db 0x50
	.db 0x01
	__endasm;

	// TODO implement return
}
