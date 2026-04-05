#include "zx_gs.h"

void ZX_GS_stop_fx_channels(uint8_t channel_mask) {
	zx_gs_data_register = channel_mask;
	zx_gs_command_register = ZX_GS_CMD_STOP_FX_CHANNELS;
	ZX_GS_wait_command_ready();
}
