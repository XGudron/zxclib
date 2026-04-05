#include "zxclib.h"
#include <stdint.h>
#include <stdio.h>

extern void bank0_test_call(void) __banked;
extern void bank1_test_call(void) __banked;

static uint16_t interrupt_counter = 0;

void my_interrupt_handler(void) __interrupt { interrupt_counter++; }

void main(void) {
	ZX_GFX_clear_screen();

	// Демонстрация базовых функций 48K
	ZX_GFX_fill_screen(ZX_COLOR_GREEN, ZX_COLOR_BLACK, ZX_BRIGHT_HIGH, ZX_FLASH_OFF);
	ZX_set_border(ZX_COLOR_BLACK);

	ZX_EVO_print("\x16\x00\x00"); // reset cursor position
	ZX_EVO_print("\x03ZX Spectrum Evolution Demo\r");
	ZX_EVO_print("\x16\x01\x28============================\r");

	ZX_EVO_toggle_memory_dispatcher(true);
	ZX_EVO_select_mode(ZX_EVO_MODE_PENTAGON_1024);
	ZX_EVO_set_cpu_speed(ZX_EVO_CPU_14MHZ);
	ZX_EVO_set_video_mode(ZX_EVO_VIDEOMODE_ZX_STANDARD);

	ZX_EVO_print("Test IM2 interrupts... ");
	ZX_set_im2_handler(my_interrupt_handler);
	for (uint8_t i = 0; i < 3; i++) {
		for (uint16_t j = 0; j < 50000; j++) {
		}
		printf("%d ", interrupt_counter);
	}
	ZX_EVO_print("OK\r");

	ZX_EVO_print("Test Bank calls...\r");
	// ZX_EVO_set_page_dispatcher_mode(3, 0, 1, 0); <- in BASIC loader, load banks to 0xC000, switch to 4Mb adressing
	// set_bank / get_bank functions in CRT
	ZX_disable_interrupts();
	bank0_test_call();
	bank1_test_call();
	ZX_enable_interrupts();
	ZX_EVO_print("OK\r");

	ZX_EVO_print("Test shadow screen...");
	ZX_disable_interrupts();
	ZX_EVO_set_high_window_page(7);
	ZX_GFX_set_video_addr(0xC000);
	ZX_GFX_fill_screen(ZX_COLOR_GREEN, ZX_COLOR_WHITE, ZX_BRIGHT_NORMAL, ZX_FLASH_OFF);
	ZX_GFX_draw_circle(100, 100, 50);
	ZX_EVO_set_high_window_page(0);
	ZX_enable_interrupts();
	for (uint8_t i = 0; i < 9; i++) {
		ZX_EVO_set_screen(i & 0x01);
		for (uint16_t j = 0; j < 30000; j++) {
		}
	}
	ZX_EVO_print("OK\r");

	ZX_EVO_print("Test NVRAM...");
	ZX_EVO_toggle_NVRAM_in_noshadow(true);
	ZX_EVO_NVRAM_set_addr(0x02);
	uint8_t value = ZX_EVO_NVRAM_read_value();
	printf("%d minutes ", value);
	ZX_EVO_print("OK\r");

	ZX_EVO_print("Test Border...");
	for (uint8_t i = 0; i < 8; i++) {
		ZX_EVO_set_border_bright(i);
		for (uint16_t j = 0; j < 30000; j++) {
		}
		ZX_EVO_set_border(i);
		for (uint16_t j = 0; j < 30000; j++) {
		}
	}
	ZX_EVO_print("OK\r");

	ZX_EVO_print("Test Beeper...");
	for (uint16_t j = 0; j < 300; j++) {
		for (uint16_t i = 0; i < 255; i++) {
			ZX_EVO_beeper_write(i);
		}
	}
	ZX_EVO_print("OK\r");

	ZX_EVO_print("Test COVOX...");
	for (uint16_t j = 0; j < 300; j++) {
		for (uint16_t i = 0; i < 255; i++) {
			ZX_EVO_COVOX_write(i);
		}
	}
	ZX_EVO_print("OK\r");

	ZX_EVO_print("Test AY...");

	// Сбрасываем AY чип
	ZX_AY_reset();

	// Воспроизводим последовательность тонов
	ZX_AY_play_tone(0, 440, 10, 1000); // Канал A, 440 Гц, громкость 10, 1000мс
	ZX_AY_play_tone(1, 554, 10, 1000); // Канал B, 554 Гц
	ZX_AY_play_tone(2, 659, 10, 1000); // Канал C, 659 Гц

	// Воспроизводим параллельные тоны
	ZX_AY_play_tone(0, 440, 10, 0); // Канал A, 440 Гц, громкость 10, 1000мс
	ZX_AY_play_tone(1, 554, 10, 0); // Канал B, 554 Гц
	ZX_AY_play_tone(2, 659, 10, 0); // Канал C, 659 Гц
	for (volatile uint16_t i = 0; i < 50000; i++) {
	}
	ZX_AY_reset();

	// Демонстрация шума
	ZX_AY_play_noise(0, 15, 8, 1000); // Шум на канале A

	// Демонстрация огибающей
	ZX_AY_set_envelope(1000, ZX_AY_ENV_REPEAT_TRIANGLE);
	ZX_AY_set_amplitude(0, ZX_AY_AMP_ENVELOPE);
	ZX_AY_set_tone(0, 220);
	ZX_AY_set_enable(ZX_AY_ENABLE_TONE_A);

	// Задержка для огибающей
	for (volatile uint16_t i = 0; i < 50000; i++) {
	}

	// Выключаем звук
	ZX_AY_reset();

	ZX_EVO_print("OK\r");

	ZX_EVO_print("Press any key to generate NMI...");
	ZX_EVO_keyboard_wait_anykey();
	ZX_EVO_generate_NMI();
	ZX_EVO_print("OK\r");

	ZX_EVO_print("Demo completed !");

	while (1) {
	}
}
