#include "zx_gs.h"

void ZX_GS_send_one_byte_volume(uint8_t byte) {
	zx_gs_data_register = byte;
	zx_gs_command_register = ZX_GS_CMD_SEND_ONE_BYTE_VOLUME;
	ZX_GS_wait_command_ready();
}
