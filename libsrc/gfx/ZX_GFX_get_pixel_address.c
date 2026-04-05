#include "zx_gfx.h"

inline uint8_t *ZX_GFX_get_pixel_address(uint8_t x, uint8_t y) {
	uint16_t addr = ZX_GFX_VIDEO_PTR;
	addr += ((y & 0xC0) << 5);
	addr += ((y & 0x38) << 2);
	addr += ((y & 0x07) << 8);
	addr += (x >> 3);
	return (volatile uint8_t *)addr;
}
