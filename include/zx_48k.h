/**
 * @file zx_48k.h
 * @brief Библиотека функций для ZX Spectrum 48K (компилятор SDCC)
 *
 * Данная библиотека предоставляет базовые функции для работы с ZX Spectrum 48K
 *
 * Все функции используют ROM-подпрограммы ZX Spectrum для максимальной
 * совместимости и производительности.
 *
 * Автор: Dmitry Panin UA3REO
 * Компилятор: SDCC
 * Целевая платформа: ZX Spectrum 48K
 */

#ifndef ZXCLIB_48K
#define ZXCLIB_48K

#include "zx.h"
#include <stdint.h>
#include <stdlib.h>

#define ZX_SCREEN_WIDTH_PX 256
#define ZX_SCREEN_HEIGHT_PX 192
#define ZX_SCREEN_COLUMNS 32
#define ZX_SCREEN_ROWS 24

#define ZX_VIDEO_RAM_ADDR 0x4000
#define ZX_VIDEO_RAM_COUNT 0x1800
#define ZX_VIDEO_ATTR_RAM_ADDR 0x5800
#define ZX_VIDEO_ATTR_RAM_COUNT 0x300
#define ZX_ATTR_T_ADDR 0x5C8F
#define ZX_MASK_T_ADDR 0x5C90
#define ZX_CURSOR_X_ADDR 0x5C88
#define ZX_CURSOR_Y_ADDR 0x5C89

/**
 * @brief Перечисление каналов ввода-вывода ZX Spectrum
 */
typedef enum {
	ZX_CHANNEL_KEYBOARD = 0, ///< Клавиатура
	ZX_CHANNEL_BOTTOM = 1,   ///< Нижняя часть экрана
	ZX_CHANNEL_TOP = 2,      ///< Верхняя часть экрана
	ZX_CHANNEL_PRINTER = 3   ///< Принтер
} zx_channel_t;

/**
 * @brief Воспроизведение звука через встроенный динамик
 * @param divisor Делитель частоты (определяет высоту тона)
 * @param duration Длительность звука в тиках процессора
 *
 * Вызывает ROM-подпрограмму BEEPER для генерации звука.
 * Чем меньше divisor, тем выше тон звука.
 */
void ZX_48K_beeper(uint16_t divisor, uint16_t duration);

/**
 * @brief Очистка указанного количества строк снизу
 * @param rows Количество очищаемых строк
 *
 * Очищает указанное количество строк начиная с нижнего края экрана.
 */
void ZX_48K_clear_lines(uint8_t rows);

/**
 * @brief Очистка экрана и установка курсора в левый верхний угол
 *
 * Вызывает ROM-подпрограмму CLS для очистки всего экрана.
 * После вызова курсор устанавливается в позицию (0,0).
 */
void ZX_48K_clear_screen(void);

/**
 * @brief Рисование линии между точками
 * @param dx Смещение по координате X
 * @param dy Смещение по координате Y
 * @param step_x Шаг по координате X (обычно 1 или -1)
 * @param step_y Шаг по координате Y (обычно 1 или -1)
 *
 * Рисует отрезок линии между точкой PLOT, выставленной ранее и переданными координатами
 * Шаг регулируется и может быть отрицательным
 */
void ZX_48K_draw_line_step(uint8_t dx, uint8_t dy, int8_t step_x, int8_t step_y);

/**
 * @brief Рисование линии между двумя координатами
 * @param x1 Начало по координате X
 * @param y1 Начало по координате Y
 * @param x2 Конец линии X
 * @param y2 Конец линии Y
 *
 * Рисует линию между двумя координатами используя функции ROM
 */
void ZX_48K_draw_line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);

/**
 * @brief Чтение координаты X курсора
 * @return Координата X курсора (0-31)
 *
 * Возвращает текущую позицию курсора по горизонтали в символьных координатах.
 */
uint8_t ZX_48K_get_cursor_x(void);

/**
 * @brief Чтение координаты Y курсора
 * @return Координата Y курсора (0-23)
 *
 * Возвращает текущую позицию курсора по вертикали в символьных координатах.
 */
uint8_t ZX_48K_get_cursor_y(void);

/**
 * @brief Чтение одного символа с клавиатуры (стандартная функция getchar)
 * @return Код ASCII нажатой клавиши или EOF при ошибке
 *
 * Функция используется стандартными библиотеками ввода/вывода (scanf, getchar и т.д.)
 * для чтения символов с клавиатуры. Использует системный канал ввода K-CHANNEL.
 */
int ZX_48K_getchar(void);

/**
 * @brief Сканирование клавиатуры
 * @return 16-битное значение:
 *   - Младший байт (bits 0-7): состояние первой клавиши
 *   - Старший байт (bits 8-15): состояние второй клавиши
 *   - 0xFF в байте означает, что ни одна клавиша не нажата
 *
 * Возвращает текущее состояние всех клавиш клавиатуры.
 * Использует ROM-подпрограмму KEY-SCAN.
 */
uint16_t ZX_48K_keyscan(void) __naked;

/**
 * @brief Загрузка блока данных с ленты или диска
 * @param address Начальный адрес для загрузки данных
 * @param length Длина загружаемых данных
 * @param type Тип данных
 */
void ZX_48K_load_bytes(uint8_t *address, uint16_t length, uint8_t type);

/**
 * @brief Установка канала ввода-вывода
 * @param channel Канал ввода-вывода из перечисления zx_channel_t
 *
 * Переключает поток ввода-вывода между различными каналами.
 * По умолчанию используется нижняя часть экрана.
 */
void ZX_48K_open_channel(zx_channel_t channel);

/**
 * @brief Рисование пикселя на экране
 * @param x Координата X (0-255)
 * @param y Координата Y (0-175)
 *
 * Устанавливает пиксель в текущем атрибуте цвета INK.
 */
void ZX_48K_plot(uint8_t x, uint8_t y);

/**
 * @brief Вывод строки в указанной позиции экрана
 * @param x Координата X (0-31)
 * @param y Координата Y (0-23)
 * @param str Указатель на строку для вывода
 *
 * Устанавливает курсор в указанную позицию и выводит строку.
 * Использует control code AT для позиционирования курсора.
 */
void ZX_48K_print_at(uint8_t x, uint8_t y, char *str);

/**
 * @brief Вывод одного символа на экран (стандартная функция putchar)
 * @param c Код ASCII символа для вывода
 * @return Всегда возвращает 1 (успешное выполнение)
 *
 * Функция используется стандартными библиотеками ввода/вывода (printf, puts и т.д.)
 * для вывода символов на экран
 */
void ZX_48K_putchar(char chr);

/**
 * @brief Вывод одного символа в указанной позиции экрана
 * @param x Координата X (0-31)
 * @param y Координата Y (0-23)
 * @param chr Символ для вывода
 *
 * Устанавливает курсор в указанную позицию и выводит символ.
 * Использует control code AT для позиционирования курсора.
 */
void ZX_48K_print_char_at(uint8_t x, uint8_t y, char chr);

/**
 * @brief Восстановление стандартного значения регистра IY
 *
 * Восстанавливает регистр IY в стандартное значение 0x5C3A.
 * Необходимо вызывать после использования функций printf из SDCC,
 * которые могут изменять IY и нарушать работу ROM-подпрограмм.
 */
void ZX_48K_recover_IY(void);

/**
 * @brief Сохранение блока данных в ленту или диск
 * @param address Начальный адрес данных для сохранения
 * @param length Длина сохраняемых данных
 * @param type Тип данных
 */
void ZX_48K_save_bytes(uint8_t *address, uint16_t length, uint8_t type);

/**
 * @brief Сдвиг всего экрана на одну строку вверх
 *
 * Перемещает содержимое всего экрана (24 полные строки) на одну строку вверх.
 * Верхняя строка исчезает.
 */
void ZX_48K_scroll_up(void);

/**
 * @brief Установка всех атрибутов одновременно
 * @param ink Цвет чернил
 * @param paper Цвет фона
 * @param flash Режим мерцания
 * @param bright Режим яркости
 *
 * Устанавливает все основные атрибуты вывода одним вызовом.
 */
void ZX_48K_set_attributes(zx_color_t ink, zx_color_t paper, zx_bright_t flash, zx_flash_t bright);

/**
 * @brief Установка яркости (BRIGHT)
 * @param bright 0 - нормальная яркость, 1 - повышенная яркость
 *
 * Устанавливает режим яркости для последующих операций вывода.
 */
void ZX_48K_set_bright(zx_bright_t bright);

/**
 * @brief Установка позиции курсора
 * @param x Координата X курсора (0-31)
 * @param y Координата Y курсора (0-23)
 *
 * Устанавливает новую позицию курсора в символьных координатах.
 */
void ZX_48K_set_cursor_position(uint8_t x, uint8_t y);

/**
 * @brief Установка мерцания (FLASH)
 *
 * Устанавливает режим мерцания для последующих операций вывода.
 */
void ZX_48K_set_flash(zx_flash_t flash);

/**
 * @brief Установка цвета чернил (INK)
 * @param color Цвет из перечисления zx_color_t
 *
 * Устанавливает цвет переднего плана (чернил) для последующих
 * операций вывода.
 */
void ZX_48K_set_ink(zx_color_t color);

/**
 * @brief Установка цвета фона (PAPER)
 * @param color Цвет из перечисления zx_color_t
 *
 * Устанавливает цвет фона для последующих операций вывода.
 */
void ZX_48K_set_paper(zx_color_t color);

#endif
