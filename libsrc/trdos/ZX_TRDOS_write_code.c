#include <zx_trdos.h>

void ZX_TRDOS_write_code(uint8_t *src_addr, uint16_t size) {
	src_addr; // HL reg
	size;     // DE reg

	__asm
		ld c, #0x0B
		call 0x3D13
	__endasm;
}
