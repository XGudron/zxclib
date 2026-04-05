#include "zx_neogs.h"

void ZX_NEOGS_dma_setup_zx_transfer(uint32_t neo_gs_address, uint8_t direction) {
	ZX_NEOGS_dma_select_module(ZX_NEOGS_DMA_ZX);
	ZX_NEOGS_dma_set_address(neo_gs_address);
	ZX_NEOGS_dma_start_transfer(direction);
}
