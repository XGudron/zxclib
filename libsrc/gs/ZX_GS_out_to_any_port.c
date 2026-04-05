#include "zx_gs.h"

void ZX_GS_out_to_any_port(uint8_t port, uint8_t data) {
	zx_gs_data_register = port;
	zx_gs_command_register = ZX_GS_CMD_OUT_TO_ANY_PORT;
	ZX_GS_wait_command_ready();
	zx_gs_data_register = data;
	ZX_GS_wait_data_ready();
}
