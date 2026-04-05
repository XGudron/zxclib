#include "zx_gs.h"

void ZX_GS_set_high_volume(void) {
	zx_gs_command_register = ZX_GS_CMD_SET_HIGH_VOLUME;
	ZX_GS_wait_command_ready();
}
