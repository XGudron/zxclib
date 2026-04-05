#include "zx_gs.h"

void ZX_GS_enter_covox_mode(void) {
	zx_gs_command_register = ZX_GS_CMD_COVOX_MODE;
	ZX_GS_wait_command_ready();
}
