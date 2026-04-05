#include "zx_gfx.h"

void ZX_GFX_draw_triangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t x3, uint8_t y3) {
	ZX_GFX_draw_line(x1, y1, x2, y2);
	ZX_GFX_draw_line(x2, y2, x3, y3);
	ZX_GFX_draw_line(x3, y3, x1, y1);
}
