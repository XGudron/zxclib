#include <zx_trdos.h>

void ZX_TRDOS_set_buffer_addr(uint8_t *addr) {
	addr; // HL reg

	__asm
		ld c, #0x04
		call 0x3D13
	__endasm;
}
