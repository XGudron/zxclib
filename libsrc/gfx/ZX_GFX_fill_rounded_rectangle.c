#include "zx_gfx.h"

void ZX_GFX_fill_rounded_rectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t radius) {
	// Проверяем, что радиус не слишком большой
	uint16_t width = (x2 > x1) ? (x2 - x1) : (x1 - x2);
	uint16_t height = (y2 > y1) ? (y2 - y1) : (y1 - y2);

	if (radius > width / 2) {
		radius = width / 2;
	}
	if (radius > height / 2) {
		radius = height / 2;
	}

	// Заполняем центральную часть
	ZX_GFX_fill_rectangle(x1 + radius, y1, x2 - radius, y2);

	// Заполняем боковые части
	ZX_GFX_fill_rectangle(x1, y1 + radius, x1 + radius - 1, y2 - radius);
	ZX_GFX_fill_rectangle(x2 - radius + 1, y1 + radius, x2, y2 - radius);

	// Заполняем углы
	ZX_GFX_fill_circle(x1 + radius, y1 + radius, radius);
	ZX_GFX_fill_circle(x2 - radius, y1 + radius, radius);
	ZX_GFX_fill_circle(x1 + radius, y2 - radius, radius);
	ZX_GFX_fill_circle(x2 - radius, y2 - radius, radius);
}
