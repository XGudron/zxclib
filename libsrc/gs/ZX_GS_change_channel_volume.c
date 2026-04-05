#include "zx_gs.h"

void ZX_GS_change_channel_volume(uint8_t channel, uint8_t volume) {
	zx_gs_data_register = volume;
	zx_gs_command_register = ZX_GS_CMD_CHANGE_CHANNEL_VOLUME + (channel & 0x03);
	ZX_GS_wait_command_ready();
}
