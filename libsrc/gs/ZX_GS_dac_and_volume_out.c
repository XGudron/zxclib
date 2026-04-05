#include "zx_gs.h"

void ZX_GS_dac_and_volume_out(uint8_t fbyte, uint8_t sbyte) {
	zx_gs_data_register = fbyte;
	zx_gs_command_register = ZX_GS_CMD_DAC_AND_VOLUME_OUT;
	ZX_GS_wait_command_ready();
	zx_gs_data_register = sbyte;
	ZX_GS_wait_data_ready();
}
