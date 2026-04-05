#include "zx_gs.h"

uint8_t ZX_GS_get_tempo_value(void) {
	zx_gs_command_register = ZX_GS_CMD_GET_TEMPO_VALUE;
	ZX_GS_wait_command_ready();
	ZX_GS_wait_data_available();
	return zx_gs_output_register;
}
