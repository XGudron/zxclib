#include "zx_gs.h"

void ZX_GS_set_e_bits(uint8_t chan) {
	zx_gs_data_register = chan;
	zx_gs_command_register = ZX_GS_CMD_SET_E_BITS;
	ZX_GS_wait_command_ready();
}
