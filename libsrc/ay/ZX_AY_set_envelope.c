#include "zx_ay.h"

void ZX_AY_set_envelope(uint16_t period, zx_ay_envelope_t shape) {
	ZX_AY_write_register(ZX_AY_REG_ENV_PERIOD_FINE, period & 0xFF);
	ZX_AY_write_register(ZX_AY_REG_ENV_PERIOD_COARSE, (period >> 8) & 0xFF);
	ZX_AY_write_register(ZX_AY_REG_ENV_SHAPE, (uint8_t)shape);
}
