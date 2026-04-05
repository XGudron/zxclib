#include "zx_gfx.h"

void ZX_GFX_draw_pixel(uint8_t x, uint8_t y) {
	uint8_t *addr = ZX_GFX_get_pixel_address(x, y);
	uint8_t mask = ZX_GFX_get_pixel_mask(x);
	*addr |= mask; // Установить пиксель
}
