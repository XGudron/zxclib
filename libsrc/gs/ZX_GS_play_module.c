#include "zx_gs.h"

void ZX_GS_play_module(uint8_t module_handle) {
	zx_gs_data_register = module_handle;
	zx_gs_command_register = ZX_GS_CMD_PLAY_MODULE;
	ZX_GS_wait_command_ready();
}
