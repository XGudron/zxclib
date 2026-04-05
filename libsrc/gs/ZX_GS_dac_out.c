#include "zx_gs.h"

void ZX_GS_dac_out(uint8_t byte, uint8_t chan) {
	zx_gs_data_register = byte;
	zx_gs_command_register = ZX_GS_CMD_DAC_OUT;
	ZX_GS_wait_command_ready();
	zx_gs_data_register = chan;
	ZX_GS_wait_data_ready();
}
