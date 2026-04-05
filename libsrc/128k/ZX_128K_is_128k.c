#include "zx_128k.h"

uint8_t ZX_128K_is_128k(void) {
	volatile uint8_t *flags = (volatile uint8_t *)0x5C3B;

	// Бит 4 FLAGS указывает на 128K Basic
	return (*flags & 0x10) ? 1 : 0;
}
