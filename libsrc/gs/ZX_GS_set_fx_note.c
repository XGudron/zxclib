#include "zx_gs.h"

void ZX_GS_set_fx_note(uint8_t note) {
	zx_gs_data_register = note;
	zx_gs_command_register = ZX_GS_CMD_SET_FX_NOTE;
	ZX_GS_wait_command_ready();
}
