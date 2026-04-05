#include "zx_48k.h"

void ZX_48K_save_bytes(uint8_t *address, uint16_t length, uint8_t type) {
    address; // HL reg
    length;  // DE reg
    type; // A reg
    
    __asm
        push hl
        pop ix
        ;ld ix, hl
        call 0x04C2      ; SAVE-BYTES ROM subroutine 
    __endasm;
}
