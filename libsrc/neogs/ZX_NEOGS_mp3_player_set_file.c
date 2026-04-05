#include "zx_neogs.h"

void ZX_NEOGS_mp3_player_set_file(uint16_t file_number) {
	zx_gs_data_register = file_number & 0xFF;
	zx_gs_command_register = ZX_NEOGS_MP3_CMD_BASE;
	ZX_GS_wait_command_ready();

	zx_gs_data_register = (file_number >> 8) & 0xFF;
	ZX_GS_wait_data_ready();
}
