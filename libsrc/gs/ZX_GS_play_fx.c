#include "zx_gs.h"

void ZX_GS_play_fx(uint8_t fx_handle) {
	zx_gs_data_register = fx_handle;
	zx_gs_command_register = ZX_GS_CMD_PLAY_FX;
	ZX_GS_wait_command_ready();
}
