#include "zx_128k.h"

zx_rom_t ZX_128K_get_rom(void) { return (zx_rom_t)((*((volatile uint8_t *)ZX_PORT_128K_MEMORY_LASTVAL) & ZX_128K_ROM_MASK) ? ZX_ROM_128K : ZX_ROM_48K); }
