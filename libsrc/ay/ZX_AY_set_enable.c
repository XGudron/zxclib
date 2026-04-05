#include "zx_ay.h"

void ZX_AY_set_enable(uint8_t enable_mask) {
	ZX_AY_write_register(ZX_AY_REG_ENABLE, ~enable_mask); // low - enabled
}
