#include "zx_evo_ers.h"

void ZX_EVO_printer_putchar(char chr) {
	chr; // A reg
	// TODO implement return
	
	__asm
	RST 8
	.db 0x41
	__endasm;
}
