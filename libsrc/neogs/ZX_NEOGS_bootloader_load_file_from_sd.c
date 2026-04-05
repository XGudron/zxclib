#include "zx_neogs.h"

void ZX_NEOGS_bootloader_load_file_from_sd(uint8_t page_number, const char *file_path) {
	zx_gs_data_register = page_number;
	zx_gs_command_register = ZX_NEOGS_BOOTLOADER_CMD_LOAD_FILE_FROM_SD;
	ZX_GS_wait_command_ready();

	// Отправка строки пути
	uint8_t *path = (uint8_t *)file_path;
	while (*path) {
		zx_gs_data_register = *path++;
		ZX_GS_wait_data_ready();
	}
	// Завершающий нулевой байт
	zx_gs_data_register = 0;
	ZX_GS_wait_data_ready();
}
