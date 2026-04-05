#include "zx_neogs.h"

void ZX_NEOGS_bootloader_load_update_file(void) {
	zx_gs_command_register = ZX_NEOGS_BOOTLOADER_CMD_LOAD_UPDATE_FILE;
	ZX_GS_wait_command_ready();
}
