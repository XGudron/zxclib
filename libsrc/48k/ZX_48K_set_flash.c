#include "zx_48k.h"

void ZX_48K_set_flash(zx_flash_t flash) {
	uint8_t attr_t = *((volatile uint8_t *)ZX_ATTR_T_ADDR);
	attr_t = (attr_t & 0x7F) | (flash << 7);
	*((volatile uint8_t *)ZX_ATTR_T_ADDR) = attr_t;
}
