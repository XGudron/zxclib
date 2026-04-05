#include "zx_gfx.h"

uint16_t ZX_GFX_VIDEO_PTR = ZX_VIDEO_RAM_ADDR;
uint16_t ZX_GFX_VIDEO_ATTR_PTR = ZX_VIDEO_ATTR_RAM_ADDR;

void ZX_GFX_set_video_addr(uint16_t addr) {
	ZX_GFX_VIDEO_PTR = addr;
	ZX_GFX_VIDEO_ATTR_PTR = ZX_GFX_VIDEO_PTR + ZX_VIDEO_RAM_COUNT;
}
