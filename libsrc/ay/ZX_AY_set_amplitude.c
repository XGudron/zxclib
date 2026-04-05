#include "zx_ay.h"

void ZX_AY_set_amplitude(uint8_t channel, zx_ay_amplitude_t amplitude) {
	if (channel > 2) {
		return;
	}

	zx_ay_register_t reg = (zx_ay_register_t)(ZX_AY_REG_AMP_A + channel);
	ZX_AY_write_register(reg, (uint8_t)amplitude);
}
