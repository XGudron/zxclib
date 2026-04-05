#include "zx_gfx.h"

void ZX_GFX_set_pixel_flash(uint8_t x, uint8_t y, zx_flash_t flash) {
	uint8_t char_x = x >> 3;
	uint8_t char_y = y >> 3;
	uint16_t attr_addr = ZX_GFX_VIDEO_ATTR_PTR + (char_y * 32) + char_x;
	uint8_t attr_value = *((volatile uint8_t *)attr_addr);
	attr_value = (attr_value & 0x7F) | (flash << 7); // Сохраняем все кроме бита 7
	*((volatile uint8_t *)attr_addr) = attr_value;
}
