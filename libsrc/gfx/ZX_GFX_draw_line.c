#include "zx_gfx.h"

void ZX_GFX_draw_line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
	int16_t dx = abs(x2 - x1);
	int16_t dy = abs(y2 - y1);
	int16_t sx = (x1 < x2) ? 1 : -1;
	int16_t sy = (y1 < y2) ? 1 : -1;
	int16_t err = dx - dy;
	int16_t e2;

	while (1) {
		ZX_GFX_draw_pixel(x1, y1);

		if (x1 == x2 && y1 == y2) {
			break;
		}

		e2 = 2 * err;
		if (e2 > -dy) {
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx) {
			err += dx;
			y1 += sy;
		}
	}
}
