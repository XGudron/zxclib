#include "zx_gs.h"

void ZX_GS_out_zero_to_zero(void) {
	zx_gs_command_register = ZX_GS_CMD_OUT_ZERO_TO_ZERO;
	ZX_GS_wait_command_ready();
}
