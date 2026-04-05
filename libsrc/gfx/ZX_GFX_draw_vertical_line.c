#include "zx_gfx.h"

void ZX_GFX_draw_vertical_line(uint8_t x, uint8_t y1, uint8_t y2) {
	if (y1 > y2) {
		uint8_t temp = y1;
		y1 = y2;
		y2 = temp;
	}

	uint8_t mask = ZX_GFX_get_pixel_mask(x);

	for (uint8_t y = y1; y <= y2; y++) {
		uint8_t *addr = ZX_GFX_get_pixel_address(x, y);
		*addr |= mask;
	}
}
