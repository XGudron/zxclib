#include "zx_gfx.h"

void ZX_GFX_fill_circle(uint8_t cx, uint8_t cy, uint8_t radius) {
	int16_t x = 0;
	int16_t y = radius;
	int16_t d = 3 - 2 * radius;

	while (x <= y) {
		// Заполняем горизонтальные линии для каждой пары y
		ZX_GFX_draw_horizontal_line(cx - y, cx + y, cy + x);
		ZX_GFX_draw_horizontal_line(cx - y, cx + y, cy - x);
		ZX_GFX_draw_horizontal_line(cx - x, cx + x, cy + y);
		ZX_GFX_draw_horizontal_line(cx - x, cx + x, cy - y);

		if (d < 0) {
			d = d + 4 * x + 6;
		} else {
			d = d + 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
}
