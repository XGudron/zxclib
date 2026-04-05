#include "zx_evo_ers.h"

uint16_t ZX_EVO_fat_call_position_function(uint8_t function_id, uint16_t position) {
	function_id; // A reg
	position;    // DE reg

	__asm
	ld b, d
	ld c, e
	RST 8
	.db 0x51
	.db 0x0B
	ld d, b
	ld e, c
	ret
	__endasm;

	return 0;
}
