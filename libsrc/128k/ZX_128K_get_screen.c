#include "zx_128k.h"

zx_screen_t ZX_128K_get_screen(void) { return (zx_screen_t)((*((volatile uint8_t *)ZX_PORT_128K_MEMORY_LASTVAL) & ZX_128K_SCREEN_MASK) ? ZX_SCREEN_SHADOW : ZX_SCREEN_NORMAL); }
