#include "zx_gs.h"

void ZX_GS_get_channel_notes(uint8_t *notes) {
	zx_gs_command_register = ZX_GS_CMD_GET_CHANNEL_NOTES;
	ZX_GS_wait_command_ready();

	notes[0] = zx_gs_output_register;
	ZX_GS_wait_data_available();
	notes[1] = zx_gs_output_register;
	ZX_GS_wait_data_available();
	notes[2] = zx_gs_output_register;
	ZX_GS_wait_data_available();
	notes[3] = zx_gs_output_register;
}
