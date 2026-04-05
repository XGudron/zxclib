#include "zx_48k.h"

void ZX_48K_draw_line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
	static int16_t dx, dy;
	dx = (int16_t)x2 - (int16_t)x1;
	dy = (int16_t)y2 - (int16_t)y1;

	ZX_48K_plot(x1, y1);
	ZX_48K_draw_line_step(abs(dx), abs(dy), dx >= 0 ? 1 : -1, dy >= 0 ? 1 : -1);
}
