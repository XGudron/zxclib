#include "zx_neogs.h"

void ZX_NEOGS_mp3_player_restart(void) {
	zx_gs_data_register = ZX_NEOGS_MP3_DATA_RESTART;
	zx_gs_command_register = ZX_NEOGS_MP3_CMD_BASE;
	ZX_GS_wait_command_ready();
	ZX_GS_wait_data_available();
}
