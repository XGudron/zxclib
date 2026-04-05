#include "zx_gs.h"

void ZX_GS_reset_flags(void) {
	zx_gs_command_register = ZX_GS_CMD_RESET_FLAGS;
	ZX_GS_wait_command_ready();
}
