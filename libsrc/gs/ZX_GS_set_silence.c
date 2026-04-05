#include "zx_gs.h"

void ZX_GS_set_silence(void) {
	zx_gs_command_register = ZX_GS_CMD_SET_SILENCE;
	ZX_GS_wait_command_ready();
}
