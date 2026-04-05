#include "zx_gfx.h"

void ZX_GFX_fill_triangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t x3, uint8_t y3) {
	// Находим минимальную и максимальную Y координату
	uint8_t y_min = y1;
	uint8_t y_max = y1;

	if (y2 < y_min) {
		y_min = y2;
	}
	if (y3 < y_min) {
		y_min = y3;
	}
	if (y2 > y_max) {
		y_max = y2;
	}
	if (y3 > y_max) {
		y_max = y3;
	}

	// Заполняем треугольник построчно
	for (uint8_t y = y_min; y <= y_max; y++) {
		int16_t x_left = 256, x_right = -1;

		// Находим пересечения с каждой стороной треугольника
		// Сторона 1-2
		if ((y1 <= y && y <= y2) || (y2 <= y && y <= y1)) {
			int16_t x = x1 + (int16_t)(y - y1) * (x2 - x1) / (y2 - y1);
			if (x < x_left) {
				x_left = x;
			}
			if (x > x_right) {
				x_right = x;
			}
		}

		// Сторона 2-3
		if ((y2 <= y && y <= y3) || (y3 <= y && y <= y2)) {
			int16_t x = x2 + (int16_t)(y - y2) * (x3 - x2) / (y3 - y2);
			if (x < x_left) {
				x_left = x;
			}
			if (x > x_right) {
				x_right = x;
			}
		}

		// Сторона 3-1
		if ((y3 <= y && y <= y1) || (y1 <= y && y <= y3)) {
			int16_t x = x3 + (int16_t)(y - y3) * (x1 - x3) / (y1 - y3);
			if (x < x_left) {
				x_left = x;
			}
			if (x > x_right) {
				x_right = x;
			}
		}

		// Рисуем горизонтальную линию
		if (x_left <= x_right) {
			ZX_GFX_draw_horizontal_line(x_left, x_right, y);
		}
	}
}
