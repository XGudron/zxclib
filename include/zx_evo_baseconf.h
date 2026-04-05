/**
 * @file zx_evo_baseconf.h
 * @brief Библиотека функций для работы с ZX Spectrum Evolution
 *
 * Данная библиотека предоставляет функции портов в конфигурации BaseConf (Базовая конфигурация)
 *
 * Автор: Dmitry Panin UA3REO
 * Компилятор: SDCC
 * Целевая платформа: ZX Spectrum Evolution
 */

#ifndef ZXCLIB_EVO_BASECONF
#define ZXCLIB_EVO_BASECONF

#include "zx.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * @brief Включение теневого режима портов; разрешение записи в ПЗУ, генерация NMI, разрешение записи в fontROM.
 *
 * xxBF RW always
 *
 * 7..6: устанавливайте в 0 для совместимости
 * 5: если 1, разрешена установка и вывод цветов палитры из расширенного цветового диапазона (4 бита на компоненту цвета). 0 после сброса.
 * 4: если 1, разрешено срабатывание аппаратной ловушки. 0 после сброса.
 * 3: Генерация NMI для процессора. NMI выдаётся при переходе бита из 1 в 0. 0 после сброса.
 * 2: если 1, то разрешается загрузка в font rom. 0 после сброса.
 * 1: если 1, то запись в ПЗУ разрешена. 0 после сброса.
 * 0: если 1, то включены теневые порты. 0 после сброса.
 */
static __sfr __at 0xBF zx_evo_xxBF_port;

/**
 * @brief Включает доступ к теневым портам
 */
void ZX_EVO_toggle_shadow_ports(bool enable);

/**
 * @brief Разрешает запись в ПЗУ
 */
void ZX_EVO_toggle_ROM_write(bool enable);

/**
 * @brief Разрешает загрузку в Font ROM
 */
void ZX_EVO_toggle_fontROM_write(bool enable);

/**
 * @brief Генерация NMI для процессора
 */
void ZX_EVO_generate_NMI(void);

/**
 * @brief Разрешает срабатывание аппаратной ловушки
 */
void ZX_EVO_toggle_hardware_trap(bool enable);

/**
 * @brief Разрешает установку и вывод цветов палитры из расширенного цветового диапазона (4 бита на компоненту цвета)
 */
void ZX_EVO_toggle_extended_palette(bool enable);

/**
 * @brief Включение теневого режима портов; разрешение работы диспетчера памяти, разрешение записи палитры, управление турбо-режимом, управление видеорежимами.
 *
 * xx77 WO shadow
 *
 * 2..0: управление видеорежимами, 011 после сброса.
 * 3: управление турбо-режимом. 0 после сброса.
 * A8: 0 — выключение диспетчера памяти. 0 после сброса.
 * A9: 0 – удержание режима включения TR-DOS и теневых портов. 0 после сброса.
 * A14: 0 – разрешение записи палитры. 1 после сброса.
 */
static __sfr __banked __at 0xBC77 zx_evo_BC77_shadow_port;
static __sfr __banked __at 0xBD77 zx_evo_BD77_shadow_port;
static __sfr __banked __at 0xBE77 zx_evo_BE77_shadow_port;
static __sfr __banked __at 0xBF77 zx_evo_BF77_shadow_port;
static __sfr __banked __at 0xFC77 zx_evo_FC77_shadow_port;
static __sfr __banked __at 0xFD77 zx_evo_FD77_shadow_port;
static __sfr __banked __at 0xFE77 zx_evo_FE77_shadow_port;
static __sfr __banked __at 0xFF77 zx_evo_FF77_shadow_port;
static __sfr __banked __at 0x0CBD ZX_EVO_lastvalue_port_xx77; // Последнее записанное значение в порт #xx77

void ZX_EVO_write_port_xx77(uint8_t value);

/**
 * @brief Включение диспетчера памяти
 */
void ZX_EVO_toggle_memory_dispatcher(bool enable);

/**
 * @brief Удержание режима включения TR-DOS и теневых портов
 */
void ZX_EVO_toggle_trdos_and_shadow_hold(bool enable);

/**
 * @brief Разрешает запись палитры
 */
void ZX_EVO_toggle_palette_write(bool enable);

/**
 * @brief Управление диспетчером страниц
 *
 * xxF7 WO shadow
 *
 * Порты #3xF7, #7xF7, #BxF7 и #FxF7 относятся, соответственно, к окнам #0000..#3FFF, #4000..#7FFF, #8000..#BFFF и #C000..#FFFF.
 *
 * Формат портов #xFF7:
 * 5..0: инверсные биты номера страницы, включаемого в окно процессора. Доступны
 *  16k страницы с номерами 0..63 ОЗУ (всего 1 мегабайт) и страницы 0..31 ПЗУ (всего 512 килобайт, бит 5 игнорируется).
 * 6: бит «ramnrom»: если 0, то в данном окне процессора включается ПЗУ, если 1 — ОЗУ.
 * 7: бит «dos7ffd»: если 1, то:
 * для ОЗУ — в данном окне происходит подмена младших 3 или 6 бит (в зависимости
 * от режима ZX Spectrum 128k или pentagon 1024k) номера страницы неинверсными битами из порта #7FFD.
 * Для ПЗУ — происходит подмена младшего бита номера страницы сигналом
 * включения TR-DOS (1 если TR-DOS включен). Кроме того, происходит включение
 * теневых портов и TR-DOS («вход в TR-DOS»), если в данном окне произойдёт
 *
 * Формат портов #x7F7:
 * 7..0: инверсные биты номера страницы ОЗУ, включаемого в окно процессора.
 * Доступны 16k страницы с номерами 0..255 (всего 4 мегабайта).
 * Запись в данный порт меняет страницу в каком либо окне текущей (активной)
 * карты памяти. При этом неактивная карта памяти остаётся неизменной. Какая
 * карта памяти активна, задаёт бит 4 порта #7FFD.
 * Внимание! При записи в этот порт остаётся неизменным режим подмены младших
 * бит номера страницы ОЗУ (бит «dos7ffd» порта #xFF7). Однако, запись в #x7F7
 * безусловно включает ОЗУ в окне (очищает бит «ramnrom» порта #xFF7).
 * Данный порт отсутствует в ATM2.
 *
 * Формат портов #xBF7:
 * 0: Режим read-only для соотв. окна. 1 – режим read-only включён. 0 после сброса
 * компьютера. Действует в т.ч. и на ROM-страницы, предлагая дополнительный уровень защиты от записи в ROM.
 * Внимание: при включении в окно #0000..#3FFF страницы RAM при помощи порта
 * #EFF7 или при входе в NMI защита от записи не действует.
 * Запись в данный порт меняет страницу в каком либо окне текущей (активной) карты памяти.
 * При этом неактивная карта памяти остаётся неизменной. Какая карта памяти активна, задаёт бит 4 порта #7FFD.
 */
static __sfr __banked __at 0x3FF7 zx_evo_3FF7_shadow_port;
static __sfr __banked __at 0x7FF7 zx_evo_7FF7_shadow_port;
static __sfr __banked __at 0xBFF7 zx_evo_BFF7_shadow_port;
static __sfr __banked __at 0xFFF7 zx_evo_FFF7_shadow_port;

static __sfr __banked __at 0x37F7 zx_evo_37F7_shadow_port;
static __sfr __banked __at 0x77F7 zx_evo_77F7_shadow_port;
static __sfr __banked __at 0xB7F7 zx_evo_B7F7_shadow_port;
static __sfr __banked __at 0xF7F7 zx_evo_F7F7_shadow_port;

static __sfr __banked __at 0x3BF7 zx_evo_3BF7_shadow_port;
static __sfr __banked __at 0x7BF7 zx_evo_7BF7_shadow_port;
static __sfr __banked __at 0xBBF7 zx_evo_BBF7_shadow_port;
static __sfr __banked __at 0xFBF7 zx_evo_FBF7_shadow_port;

/**
 * @brief Управление диспетчером страниц
 *
 * window: окно памяти #0000..#3FFF, #4000..#7FFF, #8000..#BFFF, #C000..#FFFF
 *
 * page: 5..0 инверсные биты номера страницы, включаемого в окно процессора. Доступны
 *  16k страницы с номерами 0..63 ОЗУ (всего 1 мегабайт) и страницы 0..31 ПЗУ (всего 512 килобайт, бит 5 игнорируется).
 *
 * бит «ramnrom»: если 0, то в данном окне процессора включается ПЗУ, если 1 — ОЗУ
 *
 * бит «dos7ffd»: если 1, то:
 *  для ОЗУ — в данном окне происходит подмена младших 3 или 6 бит (в зависимости
 *  от режима ZX Spectrum 128k или pentagon 1024k) номера страницы неинверсными
 *  битами из порта #7FFD.
 *
 *  Для ПЗУ — происходит подмена младшего бита номера страницы сигналом
 *  включения TR-DOS (1 если TR-DOS включен). Кроме того, происходит включение
 *  теневых портов и TR-DOS («вход в TR-DOS»), если в данном окне произойдёт
 */
void ZX_EVO_set_page_dispatcher_mode(uint8_t window, uint8_t page, bool ramnrom, bool dos7ffd);

/**
 * @brief Подключает страницу ОЗУ (до 4МБ) в выбранное окно процессора
 */
void ZX_EVO_set_window_page(uint8_t window, uint8_t page);

/**
 * @brief Подключает страницу ОЗУ (до 4МБ) в верхнее окно процессора (0xC000-0xFFFF)
 */
void ZX_EVO_set_high_window_page(uint8_t page);

/**
 * @brief Включает read-only режим для активной страницы памяти в окне процессора
 */
void ZX_EVO_toggle_readonly_mode(uint8_t window, bool enable);

/**
 * @brief Переключение страниц в окне #C000..#FFFF для режимов pentagon 1024k и ZXSpectrum 128k, переключение экранов, блокировка 128k для режима ZX-Spectrum 128k, выбор карты памяти.
 *
 * 7FFD WO always
 *
 * В режиме ZX Spectrum 128k:
 * 6..7: не исп.
 * 5: при записи 1 блокируется дальнейшая запись в порт #7FFD, до перехода в режим pentagon 1024k или до сброса. 0 после сброса.
 * 4: выбор карты памяти. 0 после сброса.
 * 3: выбор экрана. 0 после сброса.
 * 2..0: замещают младшие 3 бита номера страницы, если такое замещение разрешено для какого-либо окна (см. описание портов #xxF7). 0 после сброса.
 *
 * В режиме pentagon 1024k:
 * 7..5, 2..0: замещают при необходимости младшие 6 бит номера страницы.
 * 4: выбор карты памяти.
 * 3: выбор экрана.
 */
static __sfr __banked __at 0x7FFD zx_evo_7FFD_port;
static __sfr __banked __at 0x0ABD ZX_EVO_lastvalue_port_7FFD; // Последнее записанное значение в порт #7FFD

/**
 * @brief Переключение между основным и теневым экраном
 */
void ZX_EVO_set_screen(bool screen);

/**
 * @brief Переключение карты памяти (по умолчанию настроено так, что для нижнего окна работает как выбор ПЗУ basic128/basic48)
 */
void ZX_EVO_set_memory_map(bool type);

/**
 * @brief Блокируется дальнейшая запись в порт #7FFD
 */
void ZX_EVO_block_7FFD_port(void);

/**
 * @brief Замещают младшие 3 бита номера страницы, если такое замещение разрешено для какого-либо окна
 */
void ZX_EVO_memory_page_replace(uint8_t mask);

/**
 * @brief Замещают младшие 6 битов номера страницы в режиме pentagon 1024k
 */
void ZX_EVO_memory_page_replace_pentagon(uint8_t mask);

/**
 * @brief Управление турбо-режимом, управление видеорежимами, управление режимами ZXSpectrum 128k / pentagon 1024k, включение нулевой страницы ОЗУ в окно
 * #0000..#3FFF, управление доступом к портам энергонезависимой памяти и часов
 *
 * EFF7 WO noshad
 *
 * 7: 1 разрешает доступ к портам энергонезависимой памяти и часов в нетеневом режиме.
 * 3: 1 включает в окно #0000..#3FFF нулевую страницу ОЗУ. Имеет приоритет над настройками диспетчера памяти.
 * 2: 1 включает режим ZX Spectrum 128k. 0 – режим pentagon 1024k.
 * 4: управление турбо-режимом.
 * 5, 0: управление видеорежимами.
 * Значение всех бит порта после сброса – 0.
 */
static __sfr __banked __at 0xEFF7 zx_evo_EFF7_noshadow_port;
static __sfr __banked __at 0x0BBD ZX_EVO_lastvalue_port_EFF7; // Последнее записанное значение в порт #EFF7

/**
 * @brief Разрешает доступ к портам энергонезависимой памяти и часов в нетеневом режим
 */
void ZX_EVO_toggle_NVRAM_in_noshadow(bool enable);

/**
 * @brief Включает в окно #0000..#3FFF нулевую страницу ОЗУ. Имеет приоритет над настройками диспетчера памяти.
 */
void ZX_EVO_toggle_RAM_in_low_window(bool enable);

/**
 * @brief 1 включает режим ZX Spectrum 128k. 0 – режим pentagon 1024k.
 */
typedef enum {
	ZX_EVO_MODE_PENTAGON_1024,
	ZX_EVO_MODE_SPECTRUM_128,
} zx_evo_mode_t;

void ZX_EVO_select_mode(zx_evo_mode_t mode);

/**
 * @brief Управление турбо-режимом
 */
typedef enum {
	ZX_EVO_CPU_3_5MHZ,
	ZX_EVO_CPU_7MHZ,
	ZX_EVO_CPU_14MHZ,
} zx_evo_cpu_speed_t;

void ZX_EVO_set_cpu_speed(zx_evo_cpu_speed_t cpu_speed);

/**
 * @brief Управление видеорежимами
 */
typedef enum {
	ZX_EVO_VIDEOMODE_ZX_STANDARD,
	ZX_EVO_VIDEOMODE_ZX_HW_MULTICOLOR,
	ZX_EVO_VIDEOMODE_ZX_256x192_16COLORS,
	ZX_EVO_VIDEOMODE_ATM_640x200_HW_MULTICOLOR,
	ZX_EVO_VIDEOMODE_ATM_320x200_16COLORS,
	ZX_EVO_VIDEOMODE_ATM_TEXT_80x25,
	ZX_EVO_VIDEOMODE_ATM_TEXT_80x25_ONEPAGE,
} zx_evo_video_mode_t;

void ZX_EVO_set_video_mode(zx_evo_video_mode_t mode);

/**
 * @brief Установка адреса ячейки энергонезависимой памяти и часов.
 *
 * DFF7 WO noshad, DEF7 WO shadow
 *
 * Примечание: в нетеневом режиме порт #DFF7 доступен в зависимости от бита 7 порта #EFF7. В теневом режиме порт #DEF7 доступен всегда.
 */
static __sfr __banked __at 0xDFF7 zx_evo_DFF7_noshadow_port;
static __sfr __banked __at 0xDEF7 zx_evo_DEF7_shadow_port;

/**
 * @brief Установка адреса ячейки энергонезависимой памяти и часов
 */
void ZX_EVO_NVRAM_set_addr(uint8_t addr);

/**
 * @brief Чтение/запись ячейки энергонезависимой памяти и часов
 *
 * BFF7 RW noshad, BEF7 RW shadow
 *
 * Примечание: в нетеневом режиме порт #BFF7 доступен в зависимости от бита 7 порта #EFF7. В теневом режиме порт #BEF7 доступен всегда.
 * Имеются статусные ячейки, предназначенные для чтения статуса SD карты, PS/2, EEPROM (см руководство)
 */
static __sfr __banked __at 0xBFF7 zx_evo_BFF7_noshadow_port;
static __sfr __banked __at 0xBEF7 zx_evo_BEF7_shadow_port;

/**
 * @brief Запись ячейки энергонезависимой памяти и часов, а также статусных ячеек
 */
void ZX_EVO_NVRAM_write_value(uint8_t value);

/**
 * @brief Чтение ячейки энергонезависимой памяти и часов, а также статусных ячеек
 */
uint8_t ZX_EVO_NVRAM_read_value(void);

/**
 * @brief Управление режимом ULAPLUS
 *
 * xx3B WO always
 *
 * Модификация ULAPLUS расширяет палитру стандартного ZX-режима и режима ZX hardware multicolor.
 * При включении данного режима используется дополнительная ULAPLUS-палитра, не связанная с основной. Интепретация байта атрибутов attr:
 * биты 7:6 – выбор одной из 4 подпалитр палитры ULAPLUS
 * биты 5:3 – выбор номера цвета PAPER
 * биты 2:0 – выбор номер цвета INK
 * Палитра ULAPLUS имеет 64 позиции и задаёт цвет следующим образом:
 * цвет PAPER – из элемента палитры с номером attr[7:6]*16 + attr[5:3] + 8
 * цвет INK – из элемента палитры с номером attr[7:6]*16 + attr[2:0]
 * Каждая позиция палитры – байт, который задаёт цвет следующим образом:
 * Зелёный – биты [7:5]
 * Красный – биты [4:2]
 * Синий – биты [1:0]
 * Для установки ULAPLUS-палитры и для включения-выключения режима ULAPLUS используются порты #FF3B и #BF3B.
 */
static __sfr __banked __at 0xBF3B zx_evo_BF3B_port;
static __sfr __banked __at 0xFF3B zx_evo_FF3B_port;

/**
 * @brief Включение/отключение ULAPLUS
 */
void ZX_EVO_ULAPLUS_toggle(bool enabled);

/**
 * @brief Установка элемента палитры ULAPLUS
 * <palette element number> ;0..63
 * <palette entry G3R3B2> ;0..255
 */
void ZX_EVO_ULAPLUS_set_palette(uint8_t palette_idx, uint8_t palette_value);

/**
 * @brief Чтение клавиатуры, запись бордюра, бипер и другое
 *
 * xxFE RW always
 *
 * Чтение:
 * 7: 1
 * 6: tape_in
 * 5: 0
 * 4..0: keyboard
 *
 * Запись:
 * 7..5: не исп.
 * 4: beeper
 * 3: tape_out
 * 2..0: цвет бордюра
 */
static __sfr __at 0xFE zx_evo_xxFE_port;
static __sfr __banked __at 0x0FBD zx_evo_0FBD_port_last_border_value;

static __sfr __banked __at 0xFEFE zx_evo_FEFE_port; // CAPS SHIFT, Z, X, C, V
static __sfr __banked __at 0xFDFE zx_evo_FDFE_port; // A, S, D, F, G
static __sfr __banked __at 0xFBFE zx_evo_FBFE_port; // Q, W, E, R, T
static __sfr __banked __at 0xF7FE zx_evo_F7FE_port; // 1, 2, 3, 4, 5
static __sfr __banked __at 0xEFFE zx_evo_EFFE_port; // 0, 9, 8, 7, 6
static __sfr __banked __at 0xDFFE zx_evo_DFFE_port; // P, O, I, U, Y
static __sfr __banked __at 0xBFFE zx_evo_BFFE_port; // ENTER, L, K, J, H
static __sfr __banked __at 0x7FFE zx_evo_7FFE_port; // SPACE, SYMBOL SHIFT, M, N, B

/**
 * @brief Чтение бита из Tape-In
 */
bool ZX_EVO_tape_read(void);

/**
 * @brief Чтение данных с клавиатуры
 */
uint8_t ZX_EVO_keyboard_read(uint8_t half_row);

/**
 * @brief Ожидает нажатия любой клавиши
 */
void ZX_EVO_keyboard_wait_anykey(void);

/**
 * @brief Установка бита в бипер
 */
void ZX_EVO_beeper_write(bool status);

/**
 * @brief Запись бита в Tape-Out
 */
void ZX_EVO_tape_write(bool status);

/**
 * @brief Установка цвета рамки экрана 0..7
 */
void ZX_EVO_set_border(zx_color_t color);

/**
 * @brief Установка бордюра в расширенной гамме
 *
 * xxF6 RW always
 *
 * Полностью дублирует функционал порта #xxFE, за исключением того, что
 * устанавливает цвета бордюра 8..15.
 */
static __sfr __at 0xF6 zx_evo_xxF6_port;

/**
 * @brief Установка цвета рамки экрана 8..15
 */
void ZX_EVO_set_border_bright(zx_color_t color);

/**
 * @brief Порт вывода 8-битного звука (covox)
 *
 * xxFB WO always
 *
 * Порт предназначен для вывода 8-битного звука. Звук выводится на биперный выход при
 * помощи широтно-импульсной модуляции с частотой около 218 кГц. Записываемые
 * значения – беззнаковые отсчёты от 0 до 255. После записи в порт #xxFB биперный выход
 * начинает работать в режиме COVOX'а вплоть до последующей записи в порт #FE, после чего
 * биперный выход начинает работать в обычном режиме.
 */
static __sfr __at 0xFB zx_evo_xxFB_port;

/**
 * @brief Запись в порт Covox
 */
void ZX_EVO_COVOX_write(uint8_t value);

/**
 * @brief Порты AY/YM
 *
 * FFFB RW always
 * BFFD WO always
 *
 * FFFB Запись – выбор номера регистра AY/YM
 * FFFB Чтение – чтение содержимого регистра AY/YM
 * BFFD Запись – запись в регистр AY/YM
 *
 * Подробная реализация функционала работы с этими портаминаходится в папке AY данной библиотеки
 */
static __sfr __banked __at 0xFFFD zx_evo_FFFD_port;
static __sfr __banked __at 0xBFFD zx_evo_BFFD_port;

/**
 * @brief Чтение состояния игрового манипулятора (kempston-джойстика)
 *
 * xx1F RO noshad
 *
 * 7: 0
 * 6: 0
 * 5: 0
 * 4: Fire
 * 3: Up
 * 2: Down
 * 1: Left
 * 0: Right
 */
static __sfr __at 0x1F zx_evo_xx1F_noshadow_port;

uint8_t ZX_EVO_read_kempston_joystick(void);

/**
 * @brief Кнопки и колесо kempston-мышки
 *
 * FADF RO always
 *
 * 7..4: Wheel counter
 * 3: 1
 * 2: MMB
 * 1: RMB
 * 0: LMB
 */
static __sfr __banked __at 0xFADF zx_evo_FADF_port;

uint8_t ZX_EVO_read_kempston_mouse_buttons(void);

/**
 * @brief X-координата kempston-мышки.
 *
 * FBDF RO always
 */
static __sfr __banked __at 0xFBDF zx_evo_FBDF_port;

uint8_t ZX_EVO_read_kempston_mouse_x(void);

/**
 * @brief Y-координата kempston-мышки.
 *
 * FFDF RO always
 */
static __sfr __banked __at 0xFFDF zx_evo_FFDF_port;

uint8_t ZX_EVO_read_kempston_mouse_y(void);

/**
 * @brief Управление сигналом CS на SD-карту
 *
 * xx77 RW noshad
 *
 * Запись: управление сигналом CS на SD-карту:
 * Биты 7..2: устанавливайте в 0 для совместимости
 * Бит 1: сигнал CS, 1 после сброса, устанавливать в 0 для выбора SD-карты
 * Бит 0: устанавливайте в 1 для совместимости с Zконтроллером
 *
 * Чтение: всегда 0 (карта всегда вставлена и в режиме R/W — в соответствии с
 * интерпретацией в Z-контроллере). Реальное наличие карты следует проверять
 * попыткой её инициализации с таймаутом.
 */
static __sfr __at 0x77 zx_evo_xx77_noshadow_port;

void ZX_EVO_SD_toggle_CS(bool status);

/**
 * @brief Управление сигналом CS на SD-карту
 *
 * xx57 RW noshad, shadow
 *
 * Запись: отсылка байта в SD-карту по SPI, одновременно принятый байт можно в
 *  дальнейшем считать из этого же порта.
 * Чтение: считать ранее принятый байт, отослать #FF в карту. Вновь принятый байт
 *  доступен при повторном чтении.
 */
static __sfr __at 0x57 zx_evo_xx57_noshadow_port;

void ZX_EVO_SD_write_byte(uint8_t data);

uint8_t ZX_EVO_SD_read_byte(void);

/**
 * @brief Работа с IDE-шиной
 *
 * #xx10 RW always
 *  Порт для записи или чтения данных, читается/пишется как младшая часть 16-битного слова (режим совместимости с nemo-ide),
 *  так и старшая тоже (расширенный режим).
 * #xx11 RW always
 *  Чтение и запись старшей части 16-битного слова (режим совместимости с nemoide).
 *  Чтение происходит после чтения #10, запись сюда — до записи в #10.
 *  Обращение к этому порту не приводит к физическому обращению в IDEустройства.
 * #xx30 RW always
 *  Порт ошибок/свойств. Этот и дальнейшие порты см. в документации на протокол
 *  ATA. Биты ША Z80 7..5 мапятся на биты адреса шины ATA 2..0, порты #10, #30,
 *  …, #F0 мапятся на CS0 шины ATA, порт #С8 — на CS1.
 * #xx50 RW always
 *  Счётчик секторов
 * #xx70 RW always
 *  Номер сектора (CHS) или биты 7..0 LBA-адреса
 * #xx90 RW always
 *  Биты номера цилиндра 7..0 (CHS) или биты 15..8 LBA-адреса
 * #xxB0 RW always
 *  Биты номера цилиндра 15..8 (CHS) или биты 23..16 LBA-адреса
 * #xxD0 RW always
 *  Номер головки (CHS) или биты 27..24 LBA-адреса, выбор устройства (master/slave), выбор режима (LBA/CHS)
 * #xxF0 RW always
 *  Регистр состояния/регистр команд
 * #xxC8 RW always
 *  Регистр состояния/управления
 */
static __sfr __at 0x10 zx_evo_xx10_port;
static __sfr __at 0x11 zx_evo_xx11_port;
static __sfr __at 0x30 zx_evo_xx30_port;
static __sfr __at 0x50 zx_evo_xx50_port;
static __sfr __at 0x70 zx_evo_xx70_port;
static __sfr __at 0x90 zx_evo_xx90_port;
static __sfr __at 0xB0 zx_evo_xxB0_port;
static __sfr __at 0xD0 zx_evo_xxD0_port;
static __sfr __at 0xF0 zx_evo_xxF0_port;
static __sfr __at 0xC8 zx_evo_xxC8_port;

/**
 * @brief Порты контроллера дисковода
 *
 * #xx1F RW shadow
 *  Регистр команд/состояния ВГ93
 * #xx3F RW shadow
 *  Регистр трека ВГ93
 * #xx5F RW shadow
 *  Регистр сектора ВГ93
 * #xx7F RW shadow
 *  Регистр данных ВГ93
 * #xxFF RW shadow
 *  «Системный» регистр.
 *  Чтение:
 *   бит 7 — состояние сигнала INTRQ от ВГ93
 *   бит 6 — состояние сигнала DRQ от ВГ93
 *   биты 5..0 — предыдущее записанное в этот порт значение.
 *  Запись:
 *   биты 1..0: выбор одного из 4 дисководов
 *   бит 2: сигнал RESET на ВГ93, 0 после сброса
 *   бит 3: сигнал HRDY на ВГ93
 *   бит 4: выбор стороны дискеты
 *
 *  Примечание:
 *  Порт контроллера дисковода xxFF и одновременно порт записи палитры.
 *  Выполняет функцию записи палитры при установленном A14=0 в порте #xx77 (WO, shadow)
 */
static __sfr __at 0x1F zx_evo_xx1F_shadow_port;
static __sfr __at 0x3F zx_evo_xx3F_shadow_port;
static __sfr __at 0x5F zx_evo_xx5F_shadow_port;
static __sfr __at 0x7F zx_evo_xx7F_shadow_port;
static __sfr __at 0xFF zx_evo_xxFF_shadow_port;

/**
 * @brief Порты RS232
 *
 * #F8EF RW always
 *  <LCR&0x80==0> DAT – регистр данных
 *  <LCR&0x80==1> DLL – младший регистр делителя
 * #F9EF RW always
 *  <LCR&0x80==0> IER – регистр разрешения прерываний (не используется)
 *  <LCR&0x80==1> DLM – старший регистр делителя
 * #FAEF RW always
 *  Запись:
 *   FCR – регистр управления FIFO
 *  Чтение:
 *   ISR – регистр статуса прерываний (не используется)
 * #FBEF RW always
 *  LCR – регистр управления линией
 * #FСEF RW always
 *  MCR – регистр управления модемом
 * #FDEF RO always
 *  LSR – регистр статуса линии
 * #FEEF RO always
 *  MSR – регистр статуса модема
 * #FFEF RW always
 *  SPR – пользовательский регистр
 */
static __sfr __banked __at 0xF8EF zx_evo_F8EF_port;
static __sfr __banked __at 0xF9EF zx_evo_F9EF_port;
static __sfr __banked __at 0xFAEF zx_evo_FAEF_port;
static __sfr __banked __at 0xFBEF zx_evo_FBEF_port;
static __sfr __banked __at 0xFDEF zx_evo_FDEF_port;
static __sfr __banked __at 0xFEEF zx_evo_FEEF_port;
static __sfr __banked __at 0xFFEF zx_evo_FFEF_port;

/**
 * @brief Порт восстановления маппинга окна #0000..#3FFF при выходе из NMI
 *
 * #xxBE WO always
 */
static __sfr __at 0xBE zx_evo_xxBE_port;

/**
 * @brief Порты чтения конфигурации и модификации поведения компьютера
 *
 * #00BD..#07BD RO always
 *  Инверсный номер включенной страницы. Распределение:
 *  #00BD..#03BD – номера страниц для окон #0000..#3FFF, #4000..#7FFF,
 *  #8000..#BFFF и #C000..#FFFF соответственно для нулевой карты памяти,
 *  #04BD..#07BD – номера страниц для единичной карты памяти.
 * #08BD RO always
 *  Биты «ramnrom»
 *   Порядок битов: бит 0 – соответствует номеру
 *   страницы, считанному из порта #00BD, бит 1 – номеру из порта #01BD и т.д.
 * #09BD RO always
 *  Биты «dos7ffd». Порядок такой же, как для порта #08BD.
 * #0ABD RO always
 *  Последнее записанное значение в порт #7FFD.
 * #0BBD RO always
 *  Последнее записанное значение в порт #EFF7.
 * #0CBD RO always
 *  Последнее записанное значение в порт #xx77. Распределение бит:
 *   биты 3:0 – соответствуют битам данных 3:0 порта #xx77,
 *   бит 7 – соответствует биту адреса A14 при записи в #xx77,
 *   бит 6 — биту адреса A9,
 *   бит 5 – биту адреса A8,
 *   бит 4 – индицирует состояние сигнала DOS: если включено ПЗУ TR-DOS
 *    стандартным методом (через вход в #3Dxx), то 1, иначе 0. Этот бит
 *    предназначен для определения факта, что в NMI произошёл вход из
 *    включенного через #3Dxx ПЗУ TR-DOS. Этот бит остаётся в 1, пока
 *    исполняется код из включенной по NMI страницы #FF в области
 *    #0000..#3FFF при условии, что в эту область не включалось ОЗУ через порт #3FF7 или #37F7.
 * #0DBD RO always
 *  Чтение текущего отображаемого цвета. Предназначен для чтения палитры.
 *  Формат считываемого значения совпадает с форматом записываемого
 *  значения в порт #FF при установке палитры, за исключением
 *  битов 2 и 3, которые не определены. Процедура считывания палитры
 *  аналогична процедуре записи, но производится чтение порта #0DBD вместо записи порта #FF.
 * #0EBD RO always
 *  Чтение текущего отображаемого байта в текстовом режиме. Предназначен для считывания шрифта.
 * #0FBD RO always
 *  Биты 3:0 – чтение последнего установленного цвета бордюра. Значения 0..7
 *  – цвет, установленный записью в порт #FE, 8..15 – в порт #F6.
 * #10BD RW always
 *  Чтение и запись младшей части адреса аппаратной ловушки
 * #11BD RW always
 *  Чтение и запись старшей части адреса аппаратной ловушки
 * #12BD RW always
 * Биты защиты от записи. Порядок такой же, как для порта #08BD.
 * #13BD RW always
 *  Биты 0..3 соответствуют дисководам A..D. Если соответствующий бит стоит
 *  в единице, то при обращении к портам TR-DOS во время работы ПЗУ TRDOS происходит подмена ПЗУ на страницу ОЗУ #FE (т.н. режим “trdos
 *  emulation”). Подмена происходит начиная со следующей
 *  команды после той, что обратилась в порты. Возврат происходит так же, как
 *  из обработчика NMI: записью в порт #xxBE (без RETN). После данной
 *  записи страница ПЗУ TR-DOS возвращается на место.
 * #14BD RW always
 *  Interrupts config
 *   бит 7 — enable enhanced mode, 0 после сброса. 1 переключает в режим «улучшенных» (несовместимых!) прерываний.
 *   биты 6..3 — всегда 0
 *   бит 2 — enable external vectoring, 0 после сброса. Единичка разрешает
 *    внешним устройствам (на ZXBUS) выдавать вектора прерываний, пропуская
 *    на них IORQ при M1=0. Разрешено использовать, если все устройства на
 *    внешней шине являются «умными» или «простыми».
 *    Вектор от «простых» устройств (один на всех) будет подставлен FPGA.
 *   бит 1 — enable internal vectoring, 0 после сброса. Единичка разрешает
 *    внутренним устройствам устанавливать свои вектора прерываний. Не
 *    зависит от всей функциональности, связанной с векторами от внешних
 *    устройств, т. к. прерывания от внутренних устройств всегда имеют
 *    приоритет над внешними. При наличии внутреннего прерывания
 *    происходит безусловная блокировка IORQ внешним устройствам в цикле подтверждения прерывания.
 *   бит 0 — enable internal interrupts autoclear, 0 после сброса. Работает только
 *    если бит 1 установлен в 1. При входе в прерывание от внутренних устройств
 *    автоматически очищается соответствующий бит статуса прерываний.
 * #15BD RW always
 *  Interrupts enable. Актуально, если бит 7 порта #14BD стоит в 1.
 *  бит 7 — при записи set/reset, при чтении 0
 *  биты 6..1 — всегда 0
 *  бит 0 — VBLANK enable, 1 — разрешено. 0 после сброса
 * #16BD RW always
 *  Interrupts status. Актуально, если бит 7 порта #14BD стоит в 1.
 *  бит 7 — при записи set/reset, при чтении 0
 *  биты 6..1 — всегда 0
 *  бит 0 — VBLANK status, 1 -- активно
 */
static __sfr __banked __at 0x00BD zx_evo_00BD_port;
static __sfr __banked __at 0x01BD zx_evo_01BD_port;
static __sfr __banked __at 0x02BD zx_evo_02BD_port;
static __sfr __banked __at 0x03BD zx_evo_03BD_port;
static __sfr __banked __at 0x04BD zx_evo_04BD_port;
static __sfr __banked __at 0x05BD zx_evo_05BD_port;
static __sfr __banked __at 0x06BD zx_evo_06BD_port;
static __sfr __banked __at 0x07BD zx_evo_07BD_port;
static __sfr __banked __at 0x08BD zx_evo_08BD_port;
static __sfr __banked __at 0x09BD zx_evo_09BD_port;
static __sfr __banked __at 0x0ABD zx_evo_0ABD_port;
static __sfr __banked __at 0x0BBD zx_evo_0BBD_port;
static __sfr __banked __at 0x0CBD zx_evo_0CBD_port;
static __sfr __banked __at 0x0DBD zx_evo_0DBD_port;
static __sfr __banked __at 0x0EBD zx_evo_0EBD_port;
static __sfr __banked __at 0x0FBD zx_evo_0FBD_port;
static __sfr __banked __at 0x10BD zx_evo_10BD_port;
static __sfr __banked __at 0x11BD zx_evo_11BD_port;
static __sfr __banked __at 0x12BD zx_evo_12BD_port;
static __sfr __banked __at 0x13BD zx_evo_13BD_port;
static __sfr __banked __at 0x14BD zx_evo_14BD_port;
static __sfr __banked __at 0x15BD zx_evo_15BD_port;
static __sfr __banked __at 0x16BD zx_evo_16BD_port;

/**
 * @brief Получает номер страницы ОЗУ (до 4МБ) в верхнем окное процессора (0xC000-0xFFFF)
 */
uint8_t ZX_EVO_get_high_window_page(void);

#endif
