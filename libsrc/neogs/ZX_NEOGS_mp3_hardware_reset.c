#include "zx_neogs.h"

void ZX_NEOGS_mp3_hardware_reset(void) {
	ZX_NEOGS_mp3_set_reset(1); // Активируем сброс
	// Пауза для сброса
	for (volatile uint16_t i = 0; i < 10000; i++)
		;
	ZX_NEOGS_mp3_set_reset(0); // Деактивируем сброс
	// Пауза после сброса
	for (volatile uint16_t i = 0; i < 10000; i++)
		;
}
