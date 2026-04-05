#include "zx_128k.h"

void ZX_128K_set_high_ram_bank(zx_ram_bank_t bank) {
	uint8_t new_value = *((volatile uint8_t *)ZX_PORT_128K_MEMORY_LASTVAL);
	new_value = (new_value & ~ZX_128K_BANK_MASK) | (bank & ZX_128K_BANK_MASK);
	*((volatile uint8_t *)ZX_PORT_128K_MEMORY_LASTVAL) = new_value;
	ZX_128k_memory_port = new_value;
}
