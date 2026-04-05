#include <zx_trdos.h>

void ZX_TRDOS_write_file_header(uint8_t file_num) {
	file_num; // A reg

	__asm
		ld c, #0x09
		call 0x3D13
	__endasm;
}
