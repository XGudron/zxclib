#include "zx_gfx.h"

inline uint8_t ZX_GFX_get_pixel_mask(uint8_t x) { return 0x80 >> (x & 7); }
