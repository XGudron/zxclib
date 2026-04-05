#include "zx_gfx.h"

uint8_t ZX_GFX_get_attributes(uint8_t x, uint8_t y) {
	uint8_t char_x = x >> 3; // Преобразование в символьные координаты
	uint8_t char_y = y >> 3;
	uint16_t attr_addr = ZX_GFX_VIDEO_ATTR_PTR + (char_y * 32) + char_x;
	return *((volatile uint8_t *)attr_addr);
}
