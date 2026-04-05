#include "zx_48k.h"

void ZX_48K_load_bytes(uint8_t *address, uint16_t length, uint8_t type) {
	address; // HL reg
	length;  // DE reg
	type;    // A reg

    __asm
        push hl
        pop ix
        ;ld ix, hl
        call 0x0556      ; LOAD-BYTES ROM subroutine
    __endasm;
}
