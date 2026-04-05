#include <zx_trdos.h>

void ZX_TRDOS_read_file(uint8_t *dest_addr, uint16_t file_size) {
	dest_addr; // HL reg
	file_size; // DE reg

	__asm
		ld a, #0x00 ; 00 - read, FF - verify
        ld (#0x5CF9), a

		ld a, #0x03
		ld c, #0x0E
		call 0x3D13
	__endasm;
}
