#include "zx_gs.h"

void ZX_GS_load_fx_data(uint8_t *data, uint16_t size) {
	uint16_t remaining = size;
	uint8_t *ptr = data;
	while (remaining > 0) {
		zx_gs_data_register = *ptr;
		ZX_GS_wait_data_ready();
		remaining--;
		ptr++;
	}
}
