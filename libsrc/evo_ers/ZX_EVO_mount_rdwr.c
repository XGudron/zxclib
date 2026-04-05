#include "zx_evo_ers.h"

void ZX_EVO_mount_rdwr(uint8_t disk_rw, uint8_t track, uint8_t sector, uint8_t *buffer) {
	disk_rw; // A reg
	track;   // L reg
	sector;  // In stack
	buffer;  // In stack

	__asm
	ld d, l;
	ld e, 4(ix)
	ld h, 6(ix)
	ld l, 5(ix)
	RST 8
	.db 0x53
	.db 0x01
	__endasm;
}
