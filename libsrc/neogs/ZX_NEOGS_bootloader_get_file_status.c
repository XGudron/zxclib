#include "zx_neogs.h"

uint8_t ZX_NEOGS_bootloader_get_file_status(void) {
	zx_gs_command_register = ZX_NEOGS_BOOTLOADER_CMD_GET_FILE_STATUS;
	ZX_GS_wait_command_ready();
	return zx_gs_data_register;
}
