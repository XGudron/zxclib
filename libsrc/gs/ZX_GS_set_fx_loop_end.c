#include "zx_gs.h"

void ZX_GS_set_fx_loop_end(uint32_t len) {
	zx_gs_data_register = len & 0xFF;
	zx_gs_command_register = ZX_GS_CMD_SET_FX_LOOP_END;
	ZX_GS_wait_command_ready();
	zx_gs_data_register = (len >> 8) & 0xFF;
	ZX_GS_wait_data_ready();
	zx_gs_data_register = (len >> 16) & 0xFF;
	ZX_GS_wait_data_ready();
}
