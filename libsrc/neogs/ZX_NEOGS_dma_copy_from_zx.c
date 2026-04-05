#include "zx_neogs.h"

void ZX_NEOGS_dma_copy_from_zx(uint16_t zx_source, uint32_t neo_gs_dest, uint16_t size) {
	// Настраиваем DMA на запись в NeoGS
	ZX_NEOGS_dma_setup_zx_transfer(neo_gs_dest, 1);
	ZX_NEOGS_dma_enable();

	// Запрещаем прерывания
	ZX_disable_interrupts();

	// Копирование через запись в область $0000-$3FFF
	uint8_t *src = (uint8_t *)zx_source;
	volatile uint8_t *dma_port = (volatile uint8_t *)0x0000;

	for (uint16_t i = 0; i < size; i++) {
		*dma_port = src[i];
	}

	// Разрешаем прерывания
	ZX_enable_interrupts();

	ZX_NEOGS_dma_disable();
}
