#include "zx_gfx.h"

void ZX_GFX_set_pixel_attributes(uint8_t x, uint8_t y, zx_color_t ink, zx_color_t paper, zx_bright_t bright, zx_flash_t flash) {
	uint8_t char_x = x >> 3; // Преобразование в символьные координаты
	uint8_t char_y = y >> 3;
	uint16_t attr_addr = ZX_GFX_VIDEO_ATTR_PTR + (char_y * 32) + char_x;
	uint8_t attr_value = (flash << 7) | (bright << 6) | (paper << 3) | ink;
	*((volatile uint8_t *)attr_addr) = attr_value;
}
