/**
 * @file zx.h
 * @brief Библиотека функций для ZX Spectrum (компилятор SDCC)
 *
 * Данная библиотека предоставляет базовые функции для работы с ZX Spectrum и Z80
 *
 * Автор: Dmitry Panin UA3REO
 * Компилятор: SDCC
 * Целевая платформа: ZX Spectrum
 */

#ifndef ZXCLIB_ZX
#define ZXCLIB_ZX

#include <stdint.h>
#include <stdlib.h>

/**
 * @brief Перечисление цветов ZX Spectrum (для INK, PAPER и т.п.)
 */
typedef enum {
	ZX_COLOR_BLACK = 0,   ///< Черный
	ZX_COLOR_BLUE = 1,    ///< Синий
	ZX_COLOR_RED = 2,     ///< Красный
	ZX_COLOR_MAGENTA = 3, ///< Пурпурный
	ZX_COLOR_GREEN = 4,   ///< Зеленый
	ZX_COLOR_CYAN = 5,    ///< Голубой
	ZX_COLOR_YELLOW = 6,  ///< Желтый
	ZX_COLOR_WHITE = 7    ///< Белый
} zx_color_t;

/**
 * @brief Перечисление яркости ZX Spectrum (для BRIGHT)
 */
typedef enum {
	ZX_BRIGHT_NORMAL = 0, ///< Нормальный
	ZX_BRIGHT_HIGH = 1,   ///< Яркий
} zx_bright_t;

/**
 * @brief Перечисление статусов мигания цвета ZX Spectrum (для FLASH)
 */
typedef enum {
	ZX_FLASH_OFF = 0, ///< Мигание выключено
	ZX_FLASH_ON = 1,  ///< Мигание включено
} zx_flash_t;

#ifndef MIN
#define MIN(a, b) (a < b ? a : b)
#endif

#ifndef MAX
#define MAX(a, b) (a > b ? a : b)
#endif

/**
 * @brief Установка цвета рамки экрана
 * @param color Цвет рамки из перечисления zx_color_t
 *
 * Изменяет цвет рамки вокруг экрана. Использует порт 0xFE.
 */
void ZX_set_border(zx_color_t color);

/**
 * @brief Установка режима прерываний IM 0
 *
 * Устанавливает режим прерываний IM 0.
 * В этом режиме при прерывании процессор ожидает инструкцию от устройства.
 * Отключает прерывания на время изменения режима, затем включает их.
 */
void ZX_set_im0(void);

/**
 * @brief Установка режима прерываний IM 1
 *
 * Устанавливает режим прерываний IM 1 (стандартный для ZX Spectrum).
 * В этом режиме при прерывании процессор автоматически выполняет RST 0x38.
 * Отключает прерывания на время изменения режима, затем включает их.
 */
void ZX_set_im1(void);

/**
 * @brief Установка пользовательской функции прерывания IM2
 * @param handler_addr Адрес пользовательской функции обработки прерывания
 *
 * Стандартно вызывается 50 раз в секунду (каждые 20ms). Обязательно необходимо объявить таблицу векторов в crt0 файле
 *
 * Пример объявления обработчика:
 * void my_interrupt_handler(void) __interrupt {
 *     // код обработчика
 * }
 */

extern uint8_t interrupt_vector_table[257]; // Таблица векторов прерываний в памяти 0xFD00
void ZX_set_im2_handler(void (*handler)(void));

/**
 * @brief Включение прерываний
 *
 * Разрешает маскируемые прерывания (IM 1).
 * Использует команду EI (Enable Interrupts).
 */
void ZX_enable_interrupts(void);

/**
 * @brief Отключение прерываний
 *
 * Запрещает маскируемые прерывания.
 * Использует команду DI (Disable Interrupts).
 */
void ZX_disable_interrupts(void);

#endif
