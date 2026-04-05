#include "zx_neogs.h"

void ZX_NEOGS_bootloader_get_page_version(uint8_t page_number, char *buffer, uint16_t buffer_size) {
	zx_gs_data_register = page_number;
	zx_gs_command_register = ZX_NEOGS_BOOTLOADER_CMD_GET_PAGE_VERSION;
	ZX_GS_wait_command_ready();

	// Чтение строки версии
	for (uint16_t i = 0; i < buffer_size; i++) {
		ZX_GS_wait_data_available();
		buffer[i] = zx_gs_data_register;
		if (buffer[i] == 0) {
			break;
		}
	}
}
