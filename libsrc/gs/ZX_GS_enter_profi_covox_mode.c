#include "zx_gs.h"

void ZX_GS_enter_profi_covox_mode(void) {
	zx_gs_data_register = 0x59;
	zx_gs_command_register = ZX_GS_CMD_PROFI_COVOX_MODE;
	ZX_GS_wait_command_ready();
}
