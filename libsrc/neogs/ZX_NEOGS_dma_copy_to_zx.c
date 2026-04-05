#include "zx_neogs.h"

void ZX_NEOGS_dma_copy_to_zx(uint32_t neo_gs_source, uint16_t zx_dest, uint16_t size) {
	// Настраиваем DMA на чтение из NeoGS
	ZX_NEOGS_dma_setup_zx_transfer(neo_gs_source, 0);
	ZX_NEOGS_dma_enable();

	// Запрещаем прерывания
	ZX_disable_interrupts();

	// Копирование через чтение из памяти $0000-$3FFF
	volatile uint8_t *dma_port = (volatile uint8_t *)0x0000;
	uint8_t *dest = (uint8_t *)zx_dest;

	// Холостое чтение (первый байт неверен)
	dest[0] = *dma_port;

	for (uint16_t i = 0; i < size; i++) {
		dest[i] = *dma_port;
	}

	// Разрешаем прерывания
	ZX_enable_interrupts();

	ZX_NEOGS_dma_disable();
}
