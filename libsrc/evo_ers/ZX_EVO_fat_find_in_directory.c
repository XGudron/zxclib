#include "zx_evo_ers.h"

uint16_t ZX_EVO_fat_find_in_directory(void) {
	__asm
	RST 8
	.db 0x51
	.db 0x06
	ld d, b
	ld e, c
	ret
	__endasm;

	return 0;
}
