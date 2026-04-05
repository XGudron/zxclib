#include "zx_ay.h"

void ZX_AY_reset(void) {
	for (uint8_t i = 0; i < 16; i++) {
		ZX_AY_write_register((zx_ay_register_t)i, i == ZX_AY_REG_ENABLE ? 0xFF : 0x00);
	}
}
