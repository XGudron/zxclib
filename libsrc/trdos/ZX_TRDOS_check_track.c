#include <zx_trdos.h>

uint8_t ZX_TRDOS_check_track(uint8_t track_number) {
	track_number; // A reg

	__asm
		ld d, a
		ld c, #0x15
		call 0x3D13
	__endasm;

	return *((volatile uint8_t *)ZX_TRDOS_DEFECT_SECTORS);
}
