#include "zx_evo_ers.h"

void ZX_EVO_printer_init(void) {
	__asm
	RST 8
	.db 0x40
	__endasm;
}
