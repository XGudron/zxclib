#include "zx_evo_ers.h"

void ZX_EVO_printer_put_token(char token) {
	token; // A reg

	__asm
	RST 8
	.db 0x42
	__endasm;
}
