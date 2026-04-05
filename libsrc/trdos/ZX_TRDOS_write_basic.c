#include <zx_trdos.h>

void ZX_TRDOS_write_basic(uint8_t *src_addr, uint16_t size, uint16_t autostart_line) {
	src_addr; // HL reg
	size;     // DE reg
	*((volatile uint16_t *)ZX_TRDOS_WRITE_BASIC) = autostart_line;

	__asm
		ld c, #0x0C
		call 0x3D13
	__endasm;
}
