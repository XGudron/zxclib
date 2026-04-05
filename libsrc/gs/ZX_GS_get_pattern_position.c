#include "zx_gs.h"

uint8_t ZX_GS_get_pattern_position(void) {
	zx_gs_command_register = ZX_GS_CMD_GET_PATTERN_POSITION;
	ZX_GS_wait_command_ready();
	return zx_gs_output_register;
}
