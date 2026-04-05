#include "zx_48k.h"

void ZX_48K_open_channel(zx_channel_t channel)
{
    channel; // parameter already in A register
  __asm
    call 0x1601 ; call CHAN-OPEN 
  __endasm;
}
