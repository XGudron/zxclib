#include "zx_128k.h"

void ZX_128K_swap_screens(void) {
	zx_screen_t current = ZX_128K_get_screen();
	ZX_128K_set_screen((current == ZX_SCREEN_NORMAL) ? ZX_SCREEN_SHADOW : ZX_SCREEN_NORMAL);
}
