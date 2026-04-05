#include "zx_evo_ers.h"

void ZX_EVO_draw_window(zx_evo_window_t *window) {
	window; // HL reg

	__asm
	push ix
	push hl
	pop ix
	RST 8
	.db 0x46
	pop ix
	__endasm;
}
