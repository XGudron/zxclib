#include "zx_evo_ers.h"

void ZX_EVO_printer_print_screen(void) {
	// TODO implement return

	__asm
	RST 8
	.db 0x43
	__endasm;
}
