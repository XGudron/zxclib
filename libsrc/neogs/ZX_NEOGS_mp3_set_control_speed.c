#include "zx_neogs.h"

void ZX_NEOGS_mp3_set_control_speed(bool spd0, bool spd1) {
	uint8_t bits = 0;
	if (spd0) {
		bits |= ZX_NEOGS_SERIAL_MC_SPD0_MASK;
	}
	if (spd1) {
		bits |= ZX_NEOGS_SERIAL_MC_SPD1_MASK;
	}

	// Сначала сбрасываем оба бита
	ZX_NEOGS_sctrl_set_bits(ZX_NEOGS_SERIAL_MC_SPD0_MASK | ZX_NEOGS_SERIAL_MC_SPD1_MASK, 0);
	// Затем устанавливаем нужные значения
	ZX_NEOGS_sctrl_set_bits(bits, 1);
}
