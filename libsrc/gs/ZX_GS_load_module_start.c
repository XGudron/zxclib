#include "zx_gs.h"

uint8_t ZX_GS_load_module_start(void) {
	zx_gs_command_register = ZX_GS_CMD_LOAD_MODULE;
	ZX_GS_wait_command_ready();
	uint8_t handle = zx_gs_output_register;
	zx_gs_command_register = ZX_GS_CMD_OPEN_STREAM;
	ZX_GS_wait_command_ready();
	return handle;
}
