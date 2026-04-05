#include "zx_ay.h"

void ZX_AY_set_tone(uint8_t channel, uint16_t tone) {
	if (channel > 2) {
		return;
	}

	zx_ay_register_t reg_coarse = (zx_ay_register_t)((channel * 2) + 1);
	zx_ay_register_t reg_fine = (zx_ay_register_t)(channel * 2);

	ZX_AY_write_register(reg_fine, tone & 0xFF);
	ZX_AY_write_register(reg_coarse, (tone >> 8) & 0x0F);
}
