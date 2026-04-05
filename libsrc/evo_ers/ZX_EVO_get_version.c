#include "zx_evo_ers.h"

uint32_t ZX_EVO_get_version(void) {
	__asm
	RST 8
	.db 0x4D
	ld h, b
	ld l, c
	ret
	__endasm;

	return 0;
}
