#include "zx_128k.h"

void ZX_128K_set_screen(zx_screen_t screen) {
	uint8_t new_value = *((volatile uint8_t *)ZX_PORT_128K_MEMORY_LASTVAL);
	if (screen == ZX_SCREEN_SHADOW) {
		new_value |= ZX_128K_SCREEN_MASK;
	} else {
		new_value &= ~ZX_128K_SCREEN_MASK;
	}
	*((volatile uint8_t *)ZX_PORT_128K_MEMORY_LASTVAL) = new_value;
	ZX_128k_memory_port = new_value;
}
