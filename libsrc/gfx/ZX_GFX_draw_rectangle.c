#include "zx_gfx.h"

void ZX_GFX_draw_rectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
	ZX_GFX_draw_horizontal_line(x1, x2, y1); // Верхняя граница
	ZX_GFX_draw_horizontal_line(x1, x2, y2); // Нижняя граница
	ZX_GFX_draw_vertical_line(x1, y1, y2);   // Левая граница
	ZX_GFX_draw_vertical_line(x2, y1, y2);   // Правая граница
}
