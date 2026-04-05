#include "zx_ay.h"

void ZX_AY_play_tone(uint8_t channel, uint16_t frequency_hz, uint8_t amplitude, uint16_t duration_ms) {
	if (channel > 2) {
		return;
	}

	// Включаем нужный канал тона
	ZX_AY_set_enable(ZX_AY_get_enable() | (ZX_AY_ENABLE_TONE_A << channel));

	// Устанавливаем параметры тона
	ZX_AY_set_tone_hz(channel, frequency_hz);
	ZX_AY_set_amplitude(channel, (zx_ay_amplitude_t)amplitude);

	if (duration_ms == 0) {
		return;
	}

	// Задержка (приблизительная, зависит от частоты процессора)
	for (uint16_t i = 0; i < duration_ms; i++) {
		for (uint16_t t = 0; t < 50; t++)
			;
	}

	// Выключаем выход
	ZX_AY_set_enable(ZX_AY_get_enable() & ~(ZX_AY_ENABLE_TONE_A << channel));
}
