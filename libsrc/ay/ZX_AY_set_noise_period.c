#include "zx_ay.h"

void ZX_AY_set_noise_period(uint8_t period) { ZX_AY_write_register(ZX_AY_REG_NOISE_PERIOD, period & 0x1F); }
