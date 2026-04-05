#include "zx_gs.h"

void ZX_GS_out_to_zero_port(uint8_t data) {
	zx_gs_data_register = data;
	zx_gs_command_register = ZX_GS_CMD_OUT_TO_ZERO_PORT;
	ZX_GS_wait_command_ready();
}
