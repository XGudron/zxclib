#include "zx_gs.h"

void ZX_GS_set_fx_priority(uint8_t priority) {
	zx_gs_data_register = priority;
	zx_gs_command_register = ZX_GS_CMD_SET_FX_PRIORITY;
	ZX_GS_wait_command_ready();
}
