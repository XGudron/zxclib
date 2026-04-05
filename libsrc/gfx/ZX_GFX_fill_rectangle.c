#include "zx_gfx.h"

void ZX_GFX_fill_rectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
	if (x1 > x2) {
		uint8_t temp = x1;
		x1 = x2;
		x2 = temp;
	}
	if (y1 > y2) {
		uint8_t temp = y1;
		y1 = y2;
		y2 = temp;
	}

	for (uint8_t y = y1; y <= y2; y++) {
		ZX_GFX_draw_horizontal_line(x1, x2, y);
	}
}
