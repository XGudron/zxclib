#include "zx_gs.h"

void ZX_GS_direct_play_fx(uint8_t channel, uint8_t sample_number) {
	zx_gs_data_register = sample_number;
	zx_gs_command_register = ZX_GS_CMD_DIRECT_PLAY_FX_BASE | (channel & 0x03);
	ZX_GS_wait_command_ready();
}
