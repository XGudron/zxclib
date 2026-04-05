#include "zx_gfx.h"

void ZX_GFX_draw_horizontal_line(uint8_t x1, uint8_t x2, uint8_t y) {
	if (x1 > x2) {
		uint8_t temp = x1;
		x1 = x2;
		x2 = temp;
	}

	uint8_t start_byte = x1 >> 3;
	uint8_t end_byte = x2 >> 3;
	uint8_t *addr = ZX_GFX_get_pixel_address(start_byte << 3, y);

	if (start_byte == end_byte) {
		// Линия в одном байте
		uint8_t start_mask = 0xFF >> (x1 & 7);
		uint8_t end_mask = 0xFF << (7 - (x2 & 7));
		uint8_t mask = start_mask & end_mask;
		*addr |= mask;
	} else {
		// Первый байт (частичная маска)
		uint8_t start_mask = 0xFF >> (x1 & 7);
		*addr |= start_mask;
		addr++;

		// Полные байты между
		for (uint8_t byte = start_byte + 1; byte < end_byte; byte++) {
			*addr = 0xFF;
			addr++;
		}

		// Последний байт (частичная маска)
		if (start_byte != end_byte) {
			uint8_t end_mask = 0xFF << (7 - (x2 & 7));
			*addr |= end_mask;
		}
	}
}
