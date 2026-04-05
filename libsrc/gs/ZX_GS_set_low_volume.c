#include "zx_gs.h"

void ZX_GS_set_low_volume(void) {
	zx_gs_command_register = ZX_GS_CMD_SET_LOW_VOLUME;
	ZX_GS_wait_command_ready();
}
