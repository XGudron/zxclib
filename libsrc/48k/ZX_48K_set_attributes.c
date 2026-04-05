#include "zx_48k.h"

void ZX_48K_set_attributes(zx_color_t ink, zx_color_t paper, zx_bright_t flash, zx_flash_t bright) {
	uint8_t attr_t = (flash << 7) | (bright << 6) | (paper << 3) | ink;
	*((volatile uint8_t *)ZX_ATTR_T_ADDR) = attr_t;
}
