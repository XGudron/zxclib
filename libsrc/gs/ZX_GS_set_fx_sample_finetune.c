#include "zx_gs.h"

void ZX_GS_set_fx_sample_finetune(uint8_t finetune) {
	zx_gs_data_register = finetune;
	zx_gs_command_register = ZX_GS_CMD_SET_FX_SAMPLE_FINETUNE;
	ZX_GS_wait_command_ready();
}
