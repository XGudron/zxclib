#include "zx_gs.h"

void ZX_GS_warm_restart(void) {
	zx_gs_command_register = ZX_GS_CMD_WARM_RESTART;
	ZX_GS_wait_command_ready();
}
