#include "zx_gs.h"

void ZX_GS_covox_output(uint8_t left, uint8_t right) {
	zx_gs_data_register = left;
	zx_gs_data_register = right;
}
