#include "zx_128k.h"

void ZX_128K_copy_between_banks(zx_ram_bank_t source_bank, uint8_t *source_addr, zx_ram_bank_t dest_bank, uint8_t *dest_addr, uint16_t length) {
	zx_ram_bank_t current_bank = ZX_128K_get_high_ram_bank();

	// Копируем данные из источника во временный буфер
	uint8_t temp_buffer[256];
	uint16_t remaining = length;
	uint16_t chunk_size;

	while (remaining > 0) {
		chunk_size = (remaining > 256) ? 256 : remaining;

		// Переключаемся на банк-источник
		ZX_128K_set_high_ram_bank(source_bank);
		for (uint16_t i = 0; i < chunk_size; i++) {
			temp_buffer[i] = *((volatile uint8_t *)(source_addr + i));
		}

		// Переключаемся на банк-назначение
		ZX_128K_set_high_ram_bank(dest_bank);
		for (uint16_t i = 0; i < chunk_size; i++) {
			*((volatile uint8_t *)(dest_addr + i)) = temp_buffer[i];
		}

		source_addr += chunk_size;
		dest_addr += chunk_size;
		remaining -= chunk_size;
	}

	// Восстанавливаем исходный банк
	ZX_128K_set_high_ram_bank(current_bank);
}
