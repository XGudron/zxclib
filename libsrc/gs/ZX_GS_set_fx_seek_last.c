#include "zx_gs.h"

void ZX_GS_set_fx_seek_last(uint8_t seek_last) {
	zx_gs_data_register = seek_last;
	zx_gs_command_register = ZX_GS_CMD_SET_FX_SEEK_LAST;
	ZX_GS_wait_command_ready();
}
