#include "zx_gs.h"

void ZX_GS_send_to_dac(uint8_t byte) {
	zx_gs_data_register = byte;
	zx_gs_command_register = ZX_GS_CMD_SEND_TO_DAC;
	ZX_GS_wait_command_ready();
}
