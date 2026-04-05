#include "zx_evo_ers.h"

void ZX_EVO_type_init(void) {
	__asm
	RST 8
	.db 0x44
	__endasm;
}
