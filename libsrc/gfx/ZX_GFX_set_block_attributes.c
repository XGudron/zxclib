#include "zx_gfx.h"

void ZX_GFX_set_block_attributes(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, zx_color_t ink, zx_color_t paper, zx_bright_t bright, zx_flash_t flash) {
	if (x1 > x2) {
		uint8_t temp = x1;
		x1 = x2;
		x2 = temp;
	}
	if (y1 > y2) {
		uint8_t temp = y1;
		y1 = y2;
		y2 = temp;
	}

	uint8_t char_x1 = x1 >> 3;
	uint8_t char_y1 = y1 >> 3;
	uint8_t char_x2 = x2 >> 3;
	uint8_t char_y2 = y2 >> 3;

	uint8_t attr_value = (flash << 7) | (bright << 6) | (paper << 3) | ink;

	for (uint8_t char_y = char_y1; char_y <= char_y2; char_y++) {
		for (uint8_t char_x = char_x1; char_x <= char_x2; char_x++) {
			uint16_t attr_addr = ZX_GFX_VIDEO_ATTR_PTR + (char_y * 32) + char_x;
			*((volatile uint8_t *)attr_addr) = attr_value;
		}
	}
}
