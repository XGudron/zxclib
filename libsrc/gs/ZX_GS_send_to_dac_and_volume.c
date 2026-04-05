#include "zx_gs.h"

void ZX_GS_send_to_dac_and_volume(uint8_t byte, uint8_t volume) {
	zx_gs_data_register = byte;
	zx_gs_command_register = ZX_GS_CMD_SEND_TO_DAC_AND_VOLUME;
	ZX_GS_wait_command_ready();
	zx_gs_data_register = volume;
	ZX_GS_wait_data_ready();
}
