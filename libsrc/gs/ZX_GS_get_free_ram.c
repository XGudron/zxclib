#include "zx_gs.h"

uint32_t ZX_GS_get_free_ram(void) {
	zx_gs_command_register = ZX_GS_CMD_GET_FREE_RAM;
	ZX_GS_wait_command_ready();

	uint8_t ram_l = zx_gs_output_register;
	ZX_GS_wait_data_available();
	uint8_t ram_m = zx_gs_output_register;
	ZX_GS_wait_data_available();
	uint8_t ram_h = zx_gs_output_register;

	return ((uint32_t)ram_h << 16) | ((uint32_t)ram_m << 8) | ram_l;
}
