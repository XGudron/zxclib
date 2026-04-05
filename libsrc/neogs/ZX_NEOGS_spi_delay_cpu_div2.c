#include "zx_neogs.h"

void ZX_NEOGS_spi_delay_cpu_div2(uint8_t ticks) {
	// Для SD-карты (Fsck=Fcpu/2) нужна пауза 16 или 18 тактов
	// Каждый NOP занимает 1 такт
	while (ticks--) {
		__asm__("nop");
	}
}
