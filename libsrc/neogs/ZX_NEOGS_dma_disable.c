#include "zx_neogs.h"

void ZX_NEOGS_dma_disable(void) {
	uint8_t control = ZX_NEOGS_dma_get_control_state();
	control &= ~0x80; // Сбросить старший бит (бит 7)
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_DMA_CONTROL_STATE, control);
}
