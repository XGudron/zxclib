#include "zx_ay.h"

void ZX_AY_play_noise(uint8_t channel, uint8_t period, uint8_t amplitude, uint16_t duration_ms) {
	if (channel > 2) {
		return;
	}

	// Включаем нужный канал шума
	ZX_AY_set_enable(ZX_AY_get_enable() | (ZX_AY_ENABLE_NOISE_A << channel));

	// Устанавливаем параметры шума
	ZX_AY_set_noise_period(period);
	ZX_AY_set_amplitude(channel, (zx_ay_amplitude_t)amplitude);

	// Задержка (приблизительная, зависит от частоты процессора)
	for (uint16_t i = 0; i < duration_ms; i++) {
		for (uint16_t t = 0; t < 50; t++)
			;
	}

	// Выключаем выход
	ZX_AY_set_enable(ZX_AY_get_enable() & ~(ZX_AY_ENABLE_NOISE_A << channel));
}
