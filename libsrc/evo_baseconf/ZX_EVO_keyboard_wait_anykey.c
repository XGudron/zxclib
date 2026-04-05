#include "zx_evo_baseconf.h"

void ZX_EVO_keyboard_wait_anykey(void) {
	uint8_t chr;
	while (1) {
		for (uint8_t i = 0; i < 8; i++) {
			chr = ZX_EVO_keyboard_read(i);
			if (chr != 31) {
				return;
			}
		}
	}
}
