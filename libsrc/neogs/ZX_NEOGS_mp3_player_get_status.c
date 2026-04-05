#include "zx_neogs.h"

uint16_t ZX_NEOGS_mp3_player_get_status(void) {
	zx_gs_data_register = ZX_NEOGS_MP3_DATA_GET_STATUS;
	zx_gs_command_register = ZX_NEOGS_MP3_CMD_BASE;
	ZX_GS_wait_command_ready();

	ZX_GS_wait_data_available();
	uint8_t low_byte = zx_gs_data_register;
	ZX_GS_wait_data_available();
	uint8_t high_byte = zx_gs_data_register;

	return (uint16_t)high_byte << 8 | low_byte;
}
