#include "zx_neogs.h"

void ZX_NEOGS_dma_stop_transfer(void) {
	uint8_t control = ZX_NEOGS_dma_get_control_state();
	control &= ~0x01; // Сбросить бита направления
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_DMA_CONTROL_STATE, control);
}
