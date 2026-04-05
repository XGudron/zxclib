#include "zx_neogs.h"

void ZX_NEOGS_bootloader_run_code(uint8_t page_number, uint16_t start_address) {
	zx_gs_data_register = page_number;
	zx_gs_command_register = ZX_NEOGS_BOOTLOADER_CMD_RUN_CODE;
	ZX_GS_wait_command_ready();

	// Отправка адреса запуска
	zx_gs_data_register = start_address & 0xFF;
	ZX_GS_wait_data_ready();
	zx_gs_data_register = (start_address >> 8) & 0xFF;
	ZX_GS_wait_data_ready();
}
