#include "zx_neogs.h"

bool ZX_NEOGS_dma_is_active(void) {
	uint8_t state = ZX_NEOGS_dma_get_control_state();
	return (state & 0x01) != 0;
}
