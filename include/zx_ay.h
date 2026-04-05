/**
 * @file zx_ay.h
 * @brief Библиотека функций для AY-3-8912 (компилятор SDCC)
 *
 * Данная библиотека предоставляет дополнительные функции для работы с AY-совместимыми чипами и платформами
 *
 * Автор: Dmitry Panin UA3REO
 * Компилятор: SDCC
 * Целевая платформа: ZX Spectrum 128K / EVO
 */

#ifndef ZXCLIB_AY
#define ZXCLIB_AY

#include <stdint.h>
#include <string.h>

// Адреса портов AY-3-8912
#define ZX_AY_PORT_REGISTER_SELECT 0xFFFD // Порт выбора регистра AY
#define ZX_AY_PORT_DATA_WRITE 0xBFFD      // Порт записи данных в AY
#define ZX_AY_PORT_DATA_READ 0xFFFD       // Порт чтения данных из AY

// Регистры AY-3-8912
typedef enum {
	ZX_AY_REG_TONE_A_FINE = 0,        // Тон канала A (младший байт) 8-bit (0-255)
	ZX_AY_REG_TONE_A_COARSE = 1,      // Тон канала A (старший байт) 4-bit (0-15)
	ZX_AY_REG_TONE_B_FINE = 2,        // Тон канала B (младший байт) 8-bit (0-255)
	ZX_AY_REG_TONE_B_COARSE = 3,      // Тон канала B (старший байт) 4-bit (0-15)
	ZX_AY_REG_TONE_C_FINE = 4,        // Тон канала C (младший байт) 8-bit (0-255)
	ZX_AY_REG_TONE_C_COARSE = 5,      // Тон канала C (старший байт) 4-bit (0-15)
	ZX_AY_REG_NOISE_PERIOD = 6,       // Период шума 5-bit (0-31)
	ZX_AY_REG_ENABLE = 7,             // Включение/выключение каналов и режимов (MIXER) 8-bit (low bit=enabled)
	ZX_AY_REG_AMP_A = 8,              // Амплитуда канала A 4-bit (0-15)
	ZX_AY_REG_AMP_B = 9,              // Амплитуда канала B 4-bit (0-15)
	ZX_AY_REG_AMP_C = 10,             // Амплитуда канала C 4-bit (0-15)
	ZX_AY_REG_ENV_PERIOD_FINE = 11,   // Период огибающей (младший байт) 8-bit (0-255)
	ZX_AY_REG_ENV_PERIOD_COARSE = 12, // Период огибающей (старший байт) 8-bit (0-255)
	ZX_AY_REG_ENV_SHAPE = 13,         // Форма огибающей 4-bit (0-15)
	ZX_AY_REG_IO_PORT_A = 14,         // Порт ввода/вывода A 8-bit (0-255)
	ZX_AY_REG_IO_PORT_B = 15          // Порт ввода/вывода B 8-bit (0-255)
} zx_ay_register_t;

// Формы огибающей AY-3-8912
typedef enum {
	ZX_AY_ENV_SINGLE_DECAY = 0x00,    // Одноразовое затухание
	ZX_AY_ENV_SINGLE_ATTACK = 0x04,   // Одноразовая атака
	ZX_AY_ENV_REPEAT_DECAY = 0x08,    // Повторяющееся затухание
	ZX_AY_ENV_REPEAT_ATTACK = 0x0C,   // Повторяющаяся атака
	ZX_AY_ENV_SINGLE_TRIANGLE = 0x09, // Одноразовый треугольник
	ZX_AY_ENV_REPEAT_TRIANGLE = 0x0D, // Повторяющийся треугольник
	ZX_AY_ENV_SINGLE_SAWTOOTH = 0x0B, // Одноразовая пилообразная
	ZX_AY_ENV_REPEAT_SAWTOOTH = 0x0F  // Повторяющаяся пилообразная
} zx_ay_envelope_t;

// Амплитуды каналов AY-3-8912
typedef enum {
	ZX_AY_AMP_FIXED_MIN = 0x00,      // Минимальная фиксированная громкость
	ZX_AY_AMP_FIXED_LEVEL_1 = 0x01,  // Уровень 1
	ZX_AY_AMP_FIXED_LEVEL_2 = 0x02,  // Уровень 2
	ZX_AY_AMP_FIXED_LEVEL_3 = 0x03,  // Уровень 3
	ZX_AY_AMP_FIXED_LEVEL_4 = 0x04,  // Уровень 4
	ZX_AY_AMP_FIXED_LEVEL_5 = 0x05,  // Уровень 5
	ZX_AY_AMP_FIXED_LEVEL_6 = 0x06,  // Уровень 6
	ZX_AY_AMP_FIXED_LEVEL_7 = 0x07,  // Уровень 7
	ZX_AY_AMP_FIXED_LEVEL_8 = 0x08,  // Уровень 8
	ZX_AY_AMP_FIXED_LEVEL_9 = 0x09,  // Уровень 9
	ZX_AY_AMP_FIXED_LEVEL_10 = 0x0A, // Уровень 10
	ZX_AY_AMP_FIXED_LEVEL_11 = 0x0B, // Уровень 11
	ZX_AY_AMP_FIXED_LEVEL_12 = 0x0C, // Уровень 12
	ZX_AY_AMP_FIXED_LEVEL_13 = 0x0D, // Уровень 13
	ZX_AY_AMP_FIXED_LEVEL_14 = 0x0E, // Уровень 14
	ZX_AY_AMP_FIXED_LEVEL_15 = 0x0F, // Уровень 15
	ZX_AY_AMP_FIXED_MAX = 0x0F,      // Максимальная фиксированная громкость
	ZX_AY_AMP_ENVELOPE = 0x10        // Использовать огибающую
} zx_ay_amplitude_t;

// Биты регистра включения AY-3-8912
#define ZX_AY_ENABLE_TONE_A 0x01    // Включить тон канала A
#define ZX_AY_ENABLE_TONE_B 0x02    // Включить тон канала B
#define ZX_AY_ENABLE_TONE_C 0x04    // Включить тон канала C
#define ZX_AY_ENABLE_NOISE_A 0x08   // Включить шум канала A
#define ZX_AY_ENABLE_NOISE_B 0x10   // Включить шум канала B
#define ZX_AY_ENABLE_NOISE_C 0x20   // Включить шум канала C
#define ZX_AY_ENABLE_IO_PORT_A 0x40 // Направление порта A (0=вход, 1=выход)
#define ZX_AY_ENABLE_IO_PORT_B 0x80 // Направление порта B (0=вход, 1=выход)

static __sfr __banked __at ZX_AY_PORT_REGISTER_SELECT ZX_ay_reg_port;
static __sfr __banked __at ZX_AY_PORT_DATA_WRITE ZX_ay_data_write;
static __sfr __banked __at ZX_AY_PORT_DATA_READ ZX_ay_data_read;

/**
 * @brief Получение активных каналов AY
 * @return Битовая маска включенных каналов
 */
uint8_t ZX_AY_get_enable(void);

/**
 * @brief Воспроизведение шума через AY
 * @param channel Канал (0=A, 1=B, 2=C)
 * @param period Период шума (0-31)
 * @param amplitude Громкость (0-15)
 * @param duration_ms Длительность в миллисекундах
 *
 * Воспроизводит шум с указанными параметрами.
 */
void ZX_AY_play_noise(uint8_t channel, uint8_t period, uint8_t amplitude, uint16_t duration_ms);

/**
 * @brief Воспроизведение тона через AY
 * @param channel Канал (0=A, 1=B, 2=C)
 * @param frequency_hz Частота в Герцах (20-20000 Гц)
 * @param amplitude Громкость (0-15)
 * @param duration_ms Длительность в миллисекундах, если 0 - звук останется включенным
 *
 * Воспроизводит тон с указанными параметрами.
 * Автоматически конвертирует частоту из Гц в значение для AY-3-8912.
 * Использует задержку процессора для определения длительности.
 */
void ZX_AY_play_tone(uint8_t channel, uint16_t frequency_hz, uint8_t amplitude, uint16_t duration_ms);

/**
 * @brief Чтение данных из регистра AY-3-8912
 * @param reg Регистр из перечисления zx_ay_register_t
 * @return Содержимое регистра
 *
 * Читает значение из указанного регистра звукового чипа AY-3-8912.
 */
uint8_t ZX_AY_read_register(zx_ay_register_t reg);

/**
 * @brief Сброс всех регистров AY-3-8912
 *
 * Устанавливает все регистры AY в начальное состояние (тишина).
 */
void ZX_AY_reset(void);

/**
 * @brief Установка амплитуды канала AY
 * @param channel Канал (0=A, 1=B, 2=C)
 * @param amplitude Амплитуда из перечисления zx_ay_amplitude_t
 *
 * Устанавливает громкость или режим огибающей для канала.
 */
void ZX_AY_set_amplitude(uint8_t channel, zx_ay_amplitude_t amplitude);

/**
 * @brief Включение/выключение каналов и режимов AY
 * @param enable_mask Битовая маска включения
 *
 * Используйте константы ZX_AY_ENABLE_* для построения маски.
 * Например: ZX_AY_ENABLE_TONE_A | ZX_AY_ENABLE_TONE_B
 */
void ZX_AY_set_enable(uint8_t enable_mask);

/**
 * @brief Установка параметров огибающей AY
 * @param period Период огибающей (0-65535)
 * @param shape Форма огибающей из перечисления zx_ay_envelope_t
 *
 * Настраивает огибающую громкости для каналов с режимом ZX_AY_AMP_ENVELOPE.
 */
void ZX_AY_set_envelope(uint16_t period, zx_ay_envelope_t shape);

/**
 * @brief Установка периода шума
 * @param period Период шума (0-31)
 *
 * Устанавливает период генератора шума AY-3-8912.
 */
void ZX_AY_set_noise_period(uint8_t period);

/**
 * @brief Установка частоты тона для канала AY
 * @param channel Канал (0=A, 1=B, 2=C)
 * @param frequency_hz Частота в Герцах (20-20000 Гц)
 *
 * Устанавливает частоту тона для указанного канала.
 */
void ZX_AY_set_tone_hz(uint8_t channel, uint16_t frequency_hz);

/**
 * @brief Установка частоты тона для канала AY
 * @param channel Канал (0=A, 1=B, 2=C)
 * @param frequency Частота в единицах AY (0-4095)
 *
 * Устанавливает частоту тона для указанного канала.
 */
void ZX_AY_set_tone(uint8_t channel, uint16_t tone);

/**
 * @brief Запись данных в регистр AY-3-8912
 * @param reg Регистр из перечисления zx_ay_register_t
 * @param data Данные для записи в регистр
 *
 * Записывает значение в указанный регистр звукового чипа AY-3-8912.
 */
void ZX_AY_write_register(zx_ay_register_t reg, uint8_t data);

#endif
