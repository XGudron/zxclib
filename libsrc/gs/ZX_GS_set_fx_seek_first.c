#include "zx_gs.h"

void ZX_GS_set_fx_seek_first(uint8_t seek_first) {
	zx_gs_data_register = seek_first;
	zx_gs_command_register = ZX_GS_CMD_SET_FX_SEEK_FIRST;
	ZX_GS_wait_command_ready();
}
