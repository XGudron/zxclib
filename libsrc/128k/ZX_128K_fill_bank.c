#include "zx_128k.h"

void ZX_128K_fill_bank(uint8_t bank, uint8_t value) {
	zx_ram_bank_t current_bank = ZX_128K_get_high_ram_bank();

	ZX_128K_set_high_ram_bank(bank);
	memset((volatile uint8_t *)0xC000, value, 0x4000); // 16KB банк
	ZX_128K_set_high_ram_bank(current_bank);
}
