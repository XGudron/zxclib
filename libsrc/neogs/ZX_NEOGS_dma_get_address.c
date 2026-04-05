#include "zx_neogs.h"

uint32_t ZX_NEOGS_dma_get_address(void) {
	uint32_t address = 0;
	address |= (uint32_t)ZX_GS_in_from_any_port(ZX_NEOGS_INNER_PORT_DMA_HIGH) << 16;
	address |= (uint32_t)ZX_GS_in_from_any_port(ZX_NEOGS_INNER_PORT_DMA_MID) << 8;
	address |= ZX_GS_in_from_any_port(ZX_NEOGS_INNER_PORT_DMA_LOW);
	return address;
}
