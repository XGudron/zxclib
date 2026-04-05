#include "zx_evo_ers.h"

void ZX_EVO_print(char *str) {
	str; // HL reg

	__asm
	RST 8
	.db 0x47
	__endasm;
}
