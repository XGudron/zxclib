#include "zx_gs.h"

void ZX_GS_cold_restart(void) {
	zx_gs_command_register = ZX_GS_CMD_COLD_RESTART;
	ZX_GS_wait_command_ready();
}
