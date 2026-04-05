#include "zx_neogs.h"

uint8_t ZX_NEOGS_mp3_player_check(void) {
	zx_gs_data_register = ZX_NEOGS_MP3_DATA_CHECK;
	zx_gs_command_register = 0x1D;
	ZX_GS_wait_command_ready();
	ZX_GS_wait_data_available();
	return zx_gs_data_register;
}
