#include "zx_gfx.h"

void ZX_GFX_draw_rounded_rectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t radius) {
	// Проверяем, что радиус не слишком большой
	uint16_t width = (x2 > x1) ? (x2 - x1) : (x1 - x2);
	uint16_t height = (y2 > y1) ? (y2 - y1) : (y1 - y2);

	if (radius > width / 2) {
		radius = width / 2;
	}
	if (radius > height / 2) {
		radius = height / 2;
	}

	// Рисуем прямые части сторон
	ZX_GFX_draw_horizontal_line(x1 + radius, x2 - radius, y1); // Верх
	ZX_GFX_draw_horizontal_line(x1 + radius, x2 - radius, y2); // Низ
	ZX_GFX_draw_vertical_line(x1, y1 + radius, y2 - radius);   // Лево
	ZX_GFX_draw_vertical_line(x2, y1 + radius, y2 - radius);   // Право

	// Рисуем четыре угловых дуги (только четверти кругов)
	int16_t x = 0;
	int16_t y = radius;
	int16_t d = 3 - 2 * radius;

	while (x <= y) {
		// Левый верхний угол (четверть круга)
		ZX_GFX_draw_pixel(x1 + radius - x, y1 + radius - y);
		ZX_GFX_draw_pixel(x1 + radius - y, y1 + radius - x);

		// Правый верхний угол (четверть круга)
		ZX_GFX_draw_pixel(x2 - radius + x, y1 + radius - y);
		ZX_GFX_draw_pixel(x2 - radius + y, y1 + radius - x);

		// Левый нижний угол (четверть круга)
		ZX_GFX_draw_pixel(x1 + radius - x, y2 - radius + y);
		ZX_GFX_draw_pixel(x1 + radius - y, y2 - radius + x);

		// Правый нижний угол (четверть круга)
		ZX_GFX_draw_pixel(x2 - radius + x, y2 - radius + y);
		ZX_GFX_draw_pixel(x2 - radius + y, y2 - radius + x);

		if (d < 0) {
			d = d + 4 * x + 6;
		} else {
			d = d + 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
}
