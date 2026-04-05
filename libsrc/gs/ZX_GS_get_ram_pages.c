#include "zx_gs.h"

uint8_t ZX_GS_get_ram_pages(void) {
	zx_gs_command_register = ZX_GS_CMD_GET_RAM_PAGES;
	ZX_GS_wait_command_ready();
	return zx_gs_output_register;
}
