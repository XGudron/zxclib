#include "zx_gs.h"

void ZX_GS_profi_covox_output(uint8_t data_byte, uint8_t command_byte) {
	zx_gs_data_register = data_byte;
	zx_gs_command_register = command_byte;
	ZX_GS_wait_command_ready();
}
