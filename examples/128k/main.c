#include "zxclib.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

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
	ZX_48K_print_at(0, 0, "ZX Spectrum 128K Demo");
	ZX_48K_print_at(0, 1, "====================");

	// Демонстрация управления банками памяти
	ZX_48K_print_at(0, 3, "Memory Banks:");
	ZX_48K_print_at(0, 4, "Current bank: ");

	// Сохраняем текущий банк и переключаемся на другой
	zx_ram_bank_t original_bank = ZX_128K_get_high_ram_bank();
	ZX_128K_set_high_ram_bank(ZX_RAM_BANK_5);

	// Выводим информацию о текущем банке
	zx_ram_bank_t current_bank = ZX_128K_get_high_ram_bank();
	char bank_char = 48 + current_bank;
	ZX_48K_print_char_at(14, 4, bank_char);

	// Очищаем банк 7 для демонстрации
	ZX_128K_fill_bank(ZX_RAM_BANK_7, 0x00);
	ZX_48K_print_at(0, 5, "Bank 7 cleared");

	// Восстанавливаем исходный банк
	ZX_128K_set_high_ram_bank(original_bank);

	// Демонстрация переключения экранов
	ZX_48K_print_at(0, 7, "Screen Switching:");
	ZX_48K_print_at(0, 8, "Current: ");

	// Показываем текущий экран
	zx_screen_t current_screen = ZX_128K_get_screen();
	ZX_48K_print_at(9, 8, current_screen == ZX_SCREEN_NORMAL ? "Normal" : "Shadow");
	for (volatile uint16_t i = 0; i < 65000; i++) {
	}

	// Переключаемся на теневой экран и рисуем там
	ZX_128K_set_screen(ZX_SCREEN_SHADOW);
	ZX_128K_set_high_ram_bank(ZX_RAM_BANK_7);
	ZX_GFX_set_video_addr(ZX_SHADOW_VIDEO_RAM_ADDR);
	ZX_GFX_fill_screen(ZX_COLOR_GREEN, ZX_COLOR_WHITE, ZX_BRIGHT_NORMAL, ZX_FLASH_OFF);
	ZX_GFX_draw_circle(100, 100, 50);

	// Небольшая задержка
	for (volatile uint16_t i = 0; i < 50000; i++) {
	}

	// Переключаем обратно на основной экран
	ZX_128K_set_screen(ZX_SCREEN_NORMAL);
	ZX_GFX_set_video_addr(ZX_VIDEO_RAM_ADDR);

	// Демонстрация AY-3-8912 звукового чипа
	ZX_48K_print_at(0, 9, "AY Sound Chip:");
	ZX_48K_print_at(0, 10, "Playing tones...");

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

	// Демонстрация двойной буферизации
	ZX_48K_print_at(0, 13, "Double Buffering:");

	// Быстрое переключение экранов
	for (uint8_t i = 0; i < 20; i++) {
		ZX_128K_swap_screens();
		for (volatile uint16_t j = 0; j < 1000; j++) {
		}
	}

	// Возвращаемся на основной экран
	ZX_128K_set_screen(ZX_SCREEN_NORMAL);
	ZX_GFX_clear_screen();
	ZX_GFX_fill_screen(ZX_COLOR_BLUE, ZX_COLOR_YELLOW, ZX_BRIGHT_NORMAL, ZX_FLASH_OFF);

	// Финальное сообщение
	ZX_48K_print_at(5, 10, "Demo Complete!");

	// Устанавливаем финальный цвет рамки
	ZX_set_border(ZX_COLOR_BLUE);

	while (1) {
	}
}
