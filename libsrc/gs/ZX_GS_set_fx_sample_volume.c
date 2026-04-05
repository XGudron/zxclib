#include "zx_gs.h"

void ZX_GS_set_fx_sample_volume(uint8_t volume) {
	zx_gs_data_register = volume;
	zx_gs_command_register = ZX_GS_CMD_SET_FX_SAMPLE_VOLUME;
	ZX_GS_wait_command_ready();
}
