#include "zx_evo_ers.h"

void ZX_EVO_scroll_down(uint8_t mode) {
	mode; // A reg

	__asm
	RST 8
	.db 0x4A
	__endasm;
}
