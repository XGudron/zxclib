#include <zx_trdos.h>

void ZX_TRDOS_read_sectors(uint8_t *addr, uint8_t sector_count, uint8_t first_sector, uint8_t track) {
	addr;         // HL reg
	sector_count; // in stack
	first_sector; // in stack
	track;        // in stack

	__asm
		ld c, #0x05
		ld b, 4(ix)
		ld e, 5(ix)
		ld d, 6(ix)
		call 0x3D13
	__endasm;
}
