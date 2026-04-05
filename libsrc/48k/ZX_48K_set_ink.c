#include "zx_48k.h"

void ZX_48K_set_ink(zx_color_t color) {
	uint8_t attr_t = *((volatile uint8_t *)ZX_ATTR_T_ADDR);
	attr_t = (attr_t & 0xF8) | color;
	*((volatile uint8_t *)ZX_ATTR_T_ADDR) = attr_t;
}
