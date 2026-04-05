#include "zxclib.h"
#include <stdint.h>

extern void bank0_test_call(void) __banked;
extern void bank1_test_call(void) __banked;

void main(void) {
	ZX_48K_open_channel(ZX_CHANNEL_TOP);
	ZX_GFX_clear_screen();

	// Проверка поддержки 128K функций
	if (!ZX_128K_is_128k()) {
		// Если не 128K, просто выводим сообщение и выходим
		ZX_48K_print_at(0, 0, "Demo requires ZX Spectrum 128K");
		while (1) {
		}
	}

	// Демонстрация базовых функций 48K
	ZX_GFX_fill_screen(ZX_COLOR_BLUE, ZX_COLOR_YELLOW, ZX_BRIGHT_NORMAL, ZX_FLASH_OFF);
	ZX_set_border(ZX_COLOR_BLACK);
	ZX_48K_print_at(0, 0, "ZX Spectrum 128K Bank Call Demo");
	ZX_48K_print_at(0, 1, "====================");

	ZX_disable_interrupts();
	bank0_test_call();
	bank1_test_call();

	while (1) {
	}
}
