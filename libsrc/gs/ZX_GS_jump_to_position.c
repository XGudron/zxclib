#include "zx_gs.h"

void ZX_GS_jump_to_position(uint8_t position) {
	zx_gs_data_register = position;
	zx_gs_command_register = ZX_GS_CMD_JUMP_TO_POSITION;
	ZX_GS_wait_command_ready();
}
