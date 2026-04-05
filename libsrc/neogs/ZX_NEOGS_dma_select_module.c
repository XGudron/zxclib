#include "zx_neogs.h"

void ZX_NEOGS_dma_select_module(uint8_t module) { ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_DMA_MODULE, module); }
