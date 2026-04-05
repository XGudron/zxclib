#include "zx_neogs.h"

void ZX_NEOGS_mp3_player_get_file_info(uint16_t entry_number, char *buffer) {
	zx_gs_data_register = entry_number & 0xFF;
	zx_gs_command_register = ZX_NEOGS_MP3_DATA_GET_FILE_INFO;
	ZX_GS_wait_command_ready();

	zx_gs_data_register = (entry_number >> 8) & 0xFF;
	ZX_GS_wait_data_ready();

	// Читаем 33 байта информации
	for (uint8_t i = 0; i < 33; i++) {
		ZX_GS_wait_data_available();
		buffer[i] = zx_gs_data_register;
	}
}
