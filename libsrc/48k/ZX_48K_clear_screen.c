#include "zx_48k.h"

void ZX_48K_clear_screen(void)
{
     __asm
    call 0x0DAF
  __endasm;
}
