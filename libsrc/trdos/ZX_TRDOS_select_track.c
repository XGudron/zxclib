#include <zx_trdos.h>

void ZX_TRDOS_select_track(uint8_t track_num) {
	track_num; // A reg

	__asm
		ld c, #0x02
		call 0x3D13
	__endasm;
}
