#include "zx_48k.h"

void ZX_48K_set_cursor_position(uint8_t x, uint8_t y) {
	ZX_48K_putchar(22); // AT control code
	ZX_48K_putchar(y);  // x coordinate
	ZX_48K_putchar(x);  // y coordinate
}
