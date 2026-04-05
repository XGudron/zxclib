#include "zx_48k.h"

void ZX_48K_print_char_at(uint8_t x, uint8_t y, char chr) {
	ZX_48K_set_cursor_position(x, y);
	ZX_48K_putchar(chr);
}
