#include "zx_gs.h"

uint8_t ZX_GS_in_from_any_port(uint8_t port) {
	zx_gs_data_register = port;
	zx_gs_command_register = ZX_GS_CMD_IN_FROM_ANY_PORT;
	ZX_GS_wait_command_ready();
	ZX_GS_wait_data_available();
	return zx_gs_output_register;
}
