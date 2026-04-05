#include "zx_gs.h"

void ZX_GS_out_volume_port(uint8_t volume) {
	zx_gs_data_register = volume;
	zx_gs_command_register = ZX_GS_CMD_OUT_VOLUME_PORT;
	ZX_GS_wait_command_ready();
}
