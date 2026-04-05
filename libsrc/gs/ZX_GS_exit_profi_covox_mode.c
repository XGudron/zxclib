#include "zx_gs.h"

void ZX_GS_exit_profi_covox_mode(void) {
	zx_gs_data_register = 0x4E;
	ZX_GS_wait_data_ready();
	zx_gs_command_register = ZX_GS_CMD_PROFI_COVOX_MODE;
	ZX_GS_wait_command_ready();
	zx_gs_command_register = 0xAA;
	ZX_GS_wait_command_ready();
}
