#include "zx_gs.h"

void ZX_GS_change_channel_note(uint8_t channel, uint8_t note) {
	zx_gs_data_register = note;
	zx_gs_command_register = ZX_GS_CMD_CHANGE_CHANNEL_NOTE + (channel & 0x03);
	ZX_GS_wait_command_ready();
}
