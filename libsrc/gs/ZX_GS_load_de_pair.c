#include "zx_gs.h"

void ZX_GS_load_de_pair(uint16_t value) {
	zx_gs_data_register = value & 0xFF;
	zx_gs_command_register = ZX_GS_CMD_LOAD_DE_PAIR;
	ZX_GS_wait_command_ready();
	zx_gs_data_register = (value >> 8) & 0xFF;
	ZX_GS_wait_data_ready();
}
