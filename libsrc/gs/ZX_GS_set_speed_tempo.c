#include "zx_gs.h"

void ZX_GS_set_speed_tempo(uint8_t speed_tempo) {
	zx_gs_data_register = speed_tempo;
	zx_gs_command_register = ZX_GS_CMD_SET_SPEED_N_TEMPO;
	ZX_GS_wait_command_ready();
}
