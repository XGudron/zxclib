#include "zx_gfx.h"

void ZX_GFX_fill_screen(zx_color_t ink, zx_color_t paper, zx_bright_t bright, zx_flash_t flash) {
	uint8_t attr_value = (flash << 7) | (bright << 6) | (paper << 3) | ink;
	memset((void *)ZX_GFX_VIDEO_ATTR_PTR, attr_value, ZX_VIDEO_ATTR_RAM_COUNT);
}
