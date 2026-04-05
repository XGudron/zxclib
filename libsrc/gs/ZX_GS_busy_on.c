#include "zx_gs.h"

void ZX_GS_busy_on(void) {
	zx_gs_command_register = ZX_GS_CMD_BUSY_ON;
	ZX_GS_wait_command_ready();
}
