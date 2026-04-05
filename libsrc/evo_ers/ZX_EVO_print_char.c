#include "zx_evo_ers.h"

void ZX_EVO_print_char(char chr) {
	chr; // A reg

	__asm
	RST 8
	.db 0x48
	__endasm;
}
