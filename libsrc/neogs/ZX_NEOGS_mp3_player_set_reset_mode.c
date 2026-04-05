#include "zx_neogs.h"

void ZX_NEOGS_mp3_player_set_reset_mode(uint8_t enable) {
	zx_gs_data_register = enable ? 0x01 : 0x00;
	zx_gs_command_register = ZX_NEOGS_MP3_DATA_SET_RESET_MODE;
	ZX_GS_wait_command_ready();
}
