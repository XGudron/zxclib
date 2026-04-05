#include "zx_128k.h"

zx_ram_bank_t ZX_128K_get_high_ram_bank(void) { return (zx_ram_bank_t)(*((volatile uint8_t *)ZX_PORT_128K_MEMORY_LASTVAL) & ZX_128K_BANK_MASK); }
