#include "zx_128k.h"

void ZX_128K_set_rom(zx_rom_t rom) {
	uint8_t new_value = *((volatile uint8_t *)ZX_PORT_128K_MEMORY_LASTVAL);
	if (rom == ZX_ROM_128K) {
		new_value |= ZX_128K_ROM_MASK;
	} else {
		new_value &= ~ZX_128K_ROM_MASK;
	}
	*((volatile uint8_t *)ZX_PORT_128K_MEMORY_LASTVAL) = new_value;
	ZX_128k_memory_port = new_value;
}
