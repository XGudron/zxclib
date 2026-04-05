#include "zx_gs.h"

void ZX_GS_get_channel_volumes(uint8_t *volumes) {
	zx_gs_command_register = ZX_GS_CMD_GET_CHANNEL_VOLUMES;
	ZX_GS_wait_command_ready();

	volumes[0] = zx_gs_output_register;
	ZX_GS_wait_data_available();
	volumes[1] = zx_gs_output_register;
	ZX_GS_wait_data_available();
	volumes[2] = zx_gs_output_register;
	ZX_GS_wait_data_available();
	volumes[3] = zx_gs_output_register;
}
