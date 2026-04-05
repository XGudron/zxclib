#include "zx_evo_ers.h"

uint8_t ZX_EVO_set_mode(zx_evo_ers_mode_t mode) {
	mode; // A reg

	__asm
	RST 8
	.db 0x4B
	ret
	__endasm;

	return 0;
}
