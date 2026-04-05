#include "zx_gfx.h"

void ZX_GFX_clear_screen(void) { memset((void *)ZX_GFX_VIDEO_PTR, 0x00, ZX_VIDEO_RAM_COUNT); }
