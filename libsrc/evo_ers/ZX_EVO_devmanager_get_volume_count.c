#include "zx_evo_ers.h"

uint8_t ZX_EVO_devmanager_get_volume_count(void) {
	__asm
	RST 8
	.db 0x50
	.db 0x02
	ld a, e;
	ret
	__endasm;

	return 0;
}
