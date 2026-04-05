#include "zx_neogs.h"

uint8_t ZX_NEOGS_bootloader_check_bootloader(void) {
	zx_gs_data_register = ZX_NEOGS_BOOTLOADER_DATA_CHECK;
	zx_gs_command_register = ZX_NEOGS_BOOTLOADER_CMD_CHECK_BOOTLOADER;
	ZX_GS_wait_command_ready();
	return zx_gs_data_register;
}
