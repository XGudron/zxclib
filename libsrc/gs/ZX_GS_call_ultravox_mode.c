#include "zx_gs.h"

void ZX_GS_call_ultravox_mode(uint8_t chans, uint8_t ch1, uint8_t ch2, uint8_t ch3, uint8_t ch4) {
	zx_gs_data_register = chans;
	zx_gs_command_register = ZX_GS_CMD_CALL_ULTRAVOX_MODE;
	ZX_GS_wait_command_ready();
	zx_gs_data_register = ch1;
	zx_gs_data_register = ch2;
	zx_gs_data_register = ch3;
	zx_gs_data_register = ch4;
}
