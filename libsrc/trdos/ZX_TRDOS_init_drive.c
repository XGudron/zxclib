#include <zx_trdos.h>

void ZX_TRDOS_init_drive(uint8_t drive_num) {
	drive_num; // A reg

	__asm
		ld c, #0x01
		call 0x3D13
	__endasm;
}
