#include "zx_gfx.h"

void ZX_GFX_draw_gliph(uint8_t x, uint8_t y, const uint8_t *buffer) {
	for (uint8_t row = 0; row < 8; row++) {
		for (uint8_t col = 0; col < 8; col++) {
			// Calculate byte and bit position in buffer
			uint16_t buffer_pos = row + (col >> 3);
			uint8_t bit_mask = 0x80 >> (col & 7);

			// Check if pixel is set in buffer
			if (buffer[buffer_pos] & bit_mask) {
				ZX_GFX_draw_pixel(x + col, y + row);
			}
		}
	}
}
