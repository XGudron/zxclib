#include "zx_neogs.h"

void ZX_NEOGS_bootloader_load_code_from_spectrum(uint8_t page_number, uint16_t source_address, uint16_t block_size) {
	zx_gs_data_register = page_number;
	zx_gs_command_register = ZX_NEOGS_BOOTLOADER_CMD_LOAD_CODE_FROM_SPECTRUM;
	ZX_GS_wait_command_ready();

	// Отправка размера блока
	zx_gs_data_register = block_size & 0xFF;
	ZX_GS_wait_data_ready();
	zx_gs_data_register = (block_size >> 8) & 0xFF;
	ZX_GS_wait_data_ready();

	// Отправка данных
	uint8_t *src = (uint8_t *)source_address;
	for (uint16_t i = 0; i < block_size; i++) {
		zx_gs_data_register = src[i];
		ZX_GS_wait_data_ready();
	}
}
