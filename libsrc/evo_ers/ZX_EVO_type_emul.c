#include "zx_evo_ers.h"

void ZX_EVO_type_emul(void) {
	// TODO implement function

	__asm
	RST 8
	.db 0x45
	__endasm;
}
