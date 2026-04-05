#include "zx_gfx.h"

void ZX_GFX_draw_circle(uint8_t cx, uint8_t cy, uint8_t radius) {
	int16_t x = 0;
	int16_t y = radius;
	int16_t d = 3 - 2 * radius;

	while (x <= y) {
		// Рисуем 8 симметричных точек
		ZX_GFX_draw_pixel(cx + x, cy + y);
		ZX_GFX_draw_pixel(cx - x, cy + y);
		ZX_GFX_draw_pixel(cx + x, cy - y);
		ZX_GFX_draw_pixel(cx - x, cy - y);
		ZX_GFX_draw_pixel(cx + y, cy + x);
		ZX_GFX_draw_pixel(cx - y, cy + x);
		ZX_GFX_draw_pixel(cx + y, cy - x);
		ZX_GFX_draw_pixel(cx - y, cy - x);

		if (d < 0) {
			d = d + 4 * x + 6;
		} else {
			d = d + 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
}
