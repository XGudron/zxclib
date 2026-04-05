#include "zx_neogs.h"

void ZX_NEOGS_dma_set_address(uint32_t address) {
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_DMA_HIGH, (address >> 16) & 0xFF);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_DMA_MID, (address >> 8) & 0xFF);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_DMA_LOW, address & 0xFF);
}
