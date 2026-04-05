#include "zx_gfx.h"

bool ZX_GFX_get_pixel(uint8_t x, uint8_t y) {
	uint8_t *addr = ZX_GFX_get_pixel_address(x, y);
	uint8_t mask = ZX_GFX_get_pixel_mask(x);
	return (*addr & mask) ? 1 : 0;
}
