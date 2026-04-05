#include "zx_gs.h"

void ZX_GS_call_sounddrive_mode(uint8_t ch1, uint8_t ch2, uint8_t ch3, uint8_t ch4) {
	zx_gs_data_register = ch1;
	zx_gs_command_register = ZX_GS_CMD_CALL_SOUNDRIVE_MODE;
	ZX_GS_wait_command_ready();
	zx_gs_data_register = ch2;
	ZX_GS_wait_data_ready();
	zx_gs_data_register = ch3;
	ZX_GS_wait_data_ready();
	zx_gs_data_register = ch4;
	ZX_GS_wait_data_ready();
}
