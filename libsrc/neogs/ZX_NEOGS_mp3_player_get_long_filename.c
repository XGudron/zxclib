#include "zx_neogs.h"

void ZX_NEOGS_mp3_player_get_long_filename(uint16_t entry_number, char *buffer) {
	zx_gs_data_register = (entry_number & 0xFF) | 0x80;
	zx_gs_command_register = ZX_NEOGS_MP3_DATA_GET_FILE_INFO;
	ZX_GS_wait_command_ready();

	zx_gs_data_register = (entry_number >> 8) & 0xFF;
	ZX_GS_wait_data_ready();

	// Читаем 256 байт
	for (uint16_t i = 0; i < 256; i++) {
		ZX_GS_wait_data_available();
		buffer[i] = zx_gs_data_register;
		if (buffer[i] == 0 && i > 0) {
			break;
		}
	}
}
