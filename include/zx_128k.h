/**
 * @file zx_128k.h
 * @brief Библиотека функций для ZX Spectrum 128K (компилятор SDCC)
 *
 * Данная библиотека предоставляет дополнительные функции для работы с ZX Spectrum 128K
 * поверх базового функционала 48K версии.
 *
 * Включает в себя:
 * - Управление дополнительными банками памяти
 * - Управление вторым экраном (shadow screen)
 * - Расширенные ROM-подпрограммы 128K
 *
 * Все функции используют ROM-подпрограммы ZX Spectrum 128K для максимальной
 * совместимости и производительности.
 *
 * Автор: Dmitry Panin UA3REO
 * Компилятор: SDCC
 * Целевая платформа: ZX Spectrum 128K
 */

#ifndef ZXCLIB_128K
#define ZXCLIB_128K

#include "zx_48k.h"
#include <stdint.h>
#include <string.h>

/*The memory map of these computers is:

0xffff +--------+--------+--------+--------+--------+--------+--------+--------+
       | Bank 0 | Bank 1 | Bank 2 | Bank 3 | Bank 4 | Bank 5 | Bank 6 | Bank 7 |
       |        |        |(also at|        |        |(also at|        |        |
       |        |        | 0x8000)|        |        | 0x4000)|        |        |
       |        |        |        |        |        | screen |        | screen |
0xc000 +--------+--------+--------+--------+--------+--------+--------+--------+
       | Bank 2 |        Any one of these pages may be switched in.
       |        |
       |        |
       |        |
0x8000 +--------+
       | Bank 5 |
       |        |
       |        |
       | screen |
0x4000 +--------+--------+
       | ROM 0  | ROM 1  | Either ROM may be switched in.
       |        |        |
       |        |        |
       |        |        |
0x0000 +--------+--------+*/

// Адреса портов управления памятью 128K
#define ZX_PORT_128K_MEMORY 0x7FFD
#define ZX_PORT_128K_SCREEN 0xFF
#define ZX_PORT_128K_MEMORY_LASTVAL 0x5B5C

// Биты порта управления памятью 0x7FFD
#define ZX_128K_BANK_MASK 0x07      // Биты 0-2: номер банка RAM (0-7)
#define ZX_128K_SCREEN_MASK 0x08    // Бит 4: выбор экрана (0=normal bank 5, 1=shadow bank 7)
#define ZX_128K_ROM_MASK 0x10       // Бит 3: выбор ROM (0=128K, 1=48K)
#define ZX_128K_DISABLE_PAGING 0x20 // Бит 5: отключение paging (1=disabled)

// Адреса видеопамяти для второго экрана
#define ZX_SHADOW_VIDEO_RAM_ADDR 0xC000
#define ZX_SHADOW_VIDEO_ATTR_RAM_ADDR 0xE000

/**
 * @brief Перечисление банков памяти ZX Spectrum 128K
 */
typedef enum {
	ZX_RAM_BANK_0 = 0, ///< Банк 0 (содержит системные переменные)
	ZX_RAM_BANK_1 = 1, ///< Банк 1
	ZX_RAM_BANK_2 = 2, ///< Банк 2 он всегда находится в 0x8000 - 0xBFFF
	ZX_RAM_BANK_3 = 3, ///< Банк 3
	ZX_RAM_BANK_4 = 4, ///< Банк 4
	ZX_RAM_BANK_5 = 5, ///< Банк 5 он всегда находится в 0x4000 - 0x7FFF
	ZX_RAM_BANK_6 = 6, ///< Банк 6
	ZX_RAM_BANK_7 = 7  ///< Банк 7
} zx_ram_bank_t;

/**
 * @brief Перечисление экранов ZX Spectrum 128K
 */
typedef enum {
	ZX_SCREEN_NORMAL = 0, ///< Основной экран (0x4000-0x57FF)
	ZX_SCREEN_SHADOW = 1  ///< Теневой экран (0xC000-0xD7FF)
} zx_screen_t;

/**
 * @brief Перечисление версий ROM ZX Spectrum 128K
 */
typedef enum {
	ZX_ROM_128K = 0, ///< ROM 128K
	ZX_ROM_48K = 1   ///< ROM 48K
} zx_rom_t;

static __sfr __banked __at ZX_PORT_128K_MEMORY ZX_128k_memory_port;

/**
 * @brief Копирование данных между банками памяти
 * @param source_bank Банк-источник
 * @param source_addr Адрес в банке-источнике
 * @param dest_bank Банк-назначение
 * @param dest_addr Адрес в банке-назначении
 * @param length Количество байт для копирования
 *
 * Копирует указанное количество байт из одного банка памяти в другой.
 * Временно переключает банки для выполнения операции.
 */
void ZX_128K_copy_between_banks(zx_ram_bank_t source_bank, uint8_t *source_addr, zx_ram_bank_t dest_bank, uint8_t *dest_addr, uint16_t length);

/**
 * @brief Очистка/заполнение банка памяти
 * @param bank Банк для очистки
 * @param value Значение для заполнения
 *
 * Заполняет весь указанный банк памяти указанным значением.
 */
void ZX_128K_fill_bank(uint8_t bank, uint8_t value);

/**
 * @brief Получение адреса атрибутов текущего экрана
 * @return Адрес текущей области атрибутов
 */
uint16_t ZX_128K_get_attr_ram_addr(void);

/**
 * @brief Получение текущего номера банка памяти
 * @return Текущий номер банка (0-7)
 */
zx_ram_bank_t ZX_128K_get_high_ram_bank(void);

/**
 * @brief Получение текущей версии ROM
 * @return Текущая версия ROM из перечисления zx_rom_t
 */
zx_rom_t ZX_128K_get_rom(void);

/**
 * @brief Получение текущего экрана
 * @return Текущий экран из перечисления zx_screen_t
 */
zx_screen_t ZX_128K_get_screen(void);

/**
 * @brief Получение адреса видеопамяти текущего экрана
 * @return Адрес текущей видеопамяти
 */
uint16_t ZX_128K_get_video_ram_addr(void);

/**
 * @brief Проверка поддержки 128K функций
 * @return 1 если это 128K модель, 0 если 48K
 *
 * Проверяет бит 4 в системной переменной FLAGS по адресу 0x5C3B.
 * Бит 4 установлен если система работает в 128K Basic.
 */
uint8_t ZX_128K_is_128k(void);

/**
 * @brief Выбор банка памяти для отображения в диапазоне 0xC000-0xFFFF
 * @param bank Номер банка из перечисления zx_ram_bank_t
 *
 * Переключает банк памяти, отображаемый в верхней области памяти.
 * Банк 0 содержит системные переменные и не должен переключаться во время работы.
 */
void ZX_128K_set_high_ram_bank(zx_ram_bank_t bank);

/**
 * @brief Переключение версии ROM
 * @param rom Версия ROM из перечисления zx_rom_t
 *
 * Переключает между ROM 48K и ROM 128K.
 */
void ZX_128K_set_rom(zx_rom_t rom);

/**
 * @brief Переключение между основным и теневым экраном
 * @param screen Экран из перечисления zx_screen_t
 *
 * Переключает отображаемый экран. Теневой экран находится по адресам
 * 0xC000-0xD7FF (видеопамять) и 0xE000-0xE7FF (атрибуты).
 */
void ZX_128K_set_screen(zx_screen_t screen);

/**
 * @brief Быстрое переключение экранов с двойной буферизацией
 *
 * Переключает между основным и теневым экраном.
 * Идеально для двойной буферизации - рисование в скрытом экране,
 * затем быстрое переключение для показа.
 */
void ZX_128K_swap_screens(void);

#endif
