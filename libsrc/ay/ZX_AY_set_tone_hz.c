#include "zx_ay.h"

void ZX_AY_set_tone_hz(uint8_t channel, uint16_t frequency_hz) {
	// Конвертация частоты из Гц в значение для AY-3-8912
	// f_ay = clock / (16 * f_hz), где clock = 1773400 Гц для ZX Spectrum
	uint16_t ay_frequency = (uint16_t)(1773400UL / (16UL * frequency_hz));

	ZX_AY_set_tone(channel, ay_frequency);
}
