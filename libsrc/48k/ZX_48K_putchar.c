#include "zx_48k.h"

void ZX_48K_putchar(char chr)
{
    chr; // in A reg
    
    __asm
        rst  0x10        ; print char ROM subprogram
    __endasm;
}
