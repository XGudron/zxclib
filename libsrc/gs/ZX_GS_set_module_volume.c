#include "zx_gs.h"

uint8_t ZX_GS_set_module_volume(uint8_t volume) {
	zx_gs_data_register = volume;
	zx_gs_command_register = ZX_GS_CMD_SET_MODULE_VOLUME;
	ZX_GS_wait_command_ready();
	return zx_gs_output_register; // Returns old volume
}
