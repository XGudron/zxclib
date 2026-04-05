#include "zx_48k.h"

extern int puts(char *str);

void ZX_48K_print_at(uint8_t x, uint8_t y, char *str) {
	ZX_48K_set_cursor_position(x, y);
	puts(str);
}
