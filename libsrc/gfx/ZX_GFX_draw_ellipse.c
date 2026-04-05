#include "zx_gfx.h"

void ZX_GFX_draw_ellipse(uint8_t cx, uint8_t cy, uint8_t rx, uint8_t ry) {
	int16_t x = 0;
	int16_t y = ry;
	int16_t rx2 = rx * rx;
	int16_t ry2 = ry * ry;
	int16_t two_rx2 = 2 * rx2;
	int16_t two_ry2 = 2 * ry2;
	int16_t p;
	int16_t px = 0;
	int16_t py = two_rx2 * y;

	// Первая область
	p = (int16_t)(ry2 - (rx2 * ry) + (0.25 * rx2));
	while (px < py) {
		ZX_GFX_draw_pixel(cx + x, cy + y);
		ZX_GFX_draw_pixel(cx - x, cy + y);
		ZX_GFX_draw_pixel(cx + x, cy - y);
		ZX_GFX_draw_pixel(cx - x, cy - y);

		x++;
		px += two_ry2;
		if (p < 0) {
			p += ry2 + px;
		} else {
			y--;
			py -= two_rx2;
			p += ry2 + px - py;
		}
	}

	// Вторая область
	p = (int16_t)(ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2);
	while (y >= 0) {
		ZX_GFX_draw_pixel(cx + x, cy + y);
		ZX_GFX_draw_pixel(cx - x, cy + y);
		ZX_GFX_draw_pixel(cx + x, cy - y);
		ZX_GFX_draw_pixel(cx - x, cy - y);

		y--;
		py -= two_rx2;
		if (p > 0) {
			p += rx2 - py;
		} else {
			x++;
			px += two_ry2;
			p += rx2 - py + px;
		}
	}
}
