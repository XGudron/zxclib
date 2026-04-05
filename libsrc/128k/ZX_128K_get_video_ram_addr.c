#include "zx_128k.h"

uint16_t ZX_128K_get_video_ram_addr(void) { return (ZX_128K_get_screen() == ZX_SCREEN_SHADOW) ? ZX_SHADOW_VIDEO_RAM_ADDR : ZX_VIDEO_RAM_ADDR; }
