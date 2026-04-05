#include "zx_neogs.h"

void ZX_NEOGS_dma_start_transfer(uint8_t direction) {
	uint8_t control = ZX_NEOGS_dma_get_control_state();
	if (direction) {
		control |= 0x01; // Установить бит записи
	} else {
		control &= ~0x01; // Установить бит чтения
	}
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_DMA_CONTROL_STATE, control);
}
