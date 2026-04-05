#include "zx_48k.h"

void ZX_48K_set_bright(zx_bright_t bright) {
	uint8_t attr_t = *((volatile uint8_t *)ZX_ATTR_T_ADDR);
	attr_t = (attr_t & 0xBF) | (bright << 6);
	*((volatile uint8_t *)ZX_ATTR_T_ADDR) = attr_t;
}
