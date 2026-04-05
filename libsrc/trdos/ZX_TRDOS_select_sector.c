#include <zx_trdos.h>

void ZX_TRDOS_select_sector(uint8_t sector_num) {
	sector_num; // A reg

	__asm
		ld c, #0x03
		call 0x3D13
	__endasm;
}
