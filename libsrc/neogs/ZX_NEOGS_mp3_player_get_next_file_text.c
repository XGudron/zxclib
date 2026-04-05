#include "zx_neogs.h"

void ZX_NEOGS_mp3_player_get_next_file_text(char *buffer) {
	zx_gs_data_register = ZX_NEOGS_MP3_DATA_GET_NEXT_FILE_TEXT;
	zx_gs_command_register = ZX_NEOGS_MP3_CMD_BASE;
	ZX_GS_wait_command_ready();

	// Читаем 5 байт
	for (uint8_t i = 0; i < 5; i++) {
		ZX_GS_wait_data_available();
		buffer[i] = zx_gs_data_register;
	}
}
