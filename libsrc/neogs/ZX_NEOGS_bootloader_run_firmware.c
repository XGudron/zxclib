#include "zx_neogs.h"

void ZX_NEOGS_bootloader_run_firmware(void) {
	zx_gs_command_register = ZX_NEOGS_BOOTLOADER_CMD_RUN_FIRMWARE;
	ZX_GS_wait_command_ready();
}
