#include "zx_gs.h"

void ZX_GS_continue_module(void) {
	zx_gs_command_register = ZX_GS_CMD_CONTINUE_MODULE;
	ZX_GS_wait_command_ready();
}
