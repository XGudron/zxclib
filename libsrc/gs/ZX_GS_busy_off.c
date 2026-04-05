#include "zx_gs.h"

void ZX_GS_busy_off(void) {
	zx_gs_command_register = ZX_GS_CMD_BUSY_OFF;
	ZX_GS_wait_command_ready();
}
