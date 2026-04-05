#include "zx_gs.h"

uint8_t ZX_GS_load_fx_signed_start(void) {
	zx_gs_data_register = 0x01; // Signed sample flag
	zx_gs_command_register = ZX_GS_CMD_LOAD_FX_SIGNED;
	ZX_GS_wait_command_ready();
	uint8_t handle = zx_gs_output_register;
	zx_gs_command_register = ZX_GS_CMD_OPEN_STREAM;
	ZX_GS_wait_command_ready();
	return handle;
}
