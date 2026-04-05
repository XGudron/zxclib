#include "zx_evo_ers.h"

void ZX_EVO_uint16_to_str(char *str, uint16_t dec) {
	str; // HL reg
	dec; // DE reg

	__asm
	RST 8
	.db 0x4C
	.db 0x05
	__endasm;
}
