#include "zx_neogs.h"

uint8_t ZX_NEOGS_mp3_player_get_fat_type(void) {
	zx_gs_data_register = ZX_NEOGS_MP3_DATA_GET_FAT_TYPE;
	zx_gs_command_register = ZX_NEOGS_MP3_CMD_BASE;
	ZX_GS_wait_command_ready();

	ZX_GS_wait_data_available();
	return zx_gs_data_register;
}
