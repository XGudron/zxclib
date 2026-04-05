#include "zx_gs.h"

void ZX_GS_stop_module(void) {
	zx_gs_command_register = ZX_GS_CMD_STOP_MODULE;
	ZX_GS_wait_command_ready();
}
