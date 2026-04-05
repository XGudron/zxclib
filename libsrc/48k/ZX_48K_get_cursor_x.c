#include "zx_48k.h"

uint8_t ZX_48K_get_cursor_x(void) { return *((volatile uint8_t *)ZX_CURSOR_X_ADDR); }
