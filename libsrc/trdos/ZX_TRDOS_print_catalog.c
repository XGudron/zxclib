#include <zx_trdos.h>

void ZX_TRDOS_print_catalog(uint8_t channel) {
	channel; // A reg

	__asm
		ld c, #0x07
		call 0x3D13
	__endasm;
}
