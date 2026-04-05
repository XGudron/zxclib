/**
 * @file zx_gs.h
 * @brief Библиотека функций для работы с General Sound
 *
 * Данная библиотека предоставляет функции General Sound, описанные в документации "Версия v1.04. Редакция 006."
 *
 * Автор: Dmitry Panin UA3REO
 * Компилятор: SDCC
 * Целевая платформа: ZX Spectrum
 */

#ifndef ZX_GS_H
#define ZX_GS_H

#include <stdint.h>

// GS Ports
#define ZX_GS_COMMAND_REGISTER_PORT 0xBB
#define ZX_GS_STATUS_REGISTER_PORT 0xBB
#define ZX_GS_DATA_REGISTER_PORT 0xB3
#define ZX_GS_OUTPUT_REGISTER_PORT 0xB3

// GS Commands
#define ZX_GS_CMD_RESET_FLAGS 0x00
#define ZX_GS_CMD_SET_SILENCE 0x01
#define ZX_GS_CMD_SET_LOW_VOLUME 0x02
#define ZX_GS_CMD_SET_HIGH_VOLUME 0x03
#define ZX_GS_CMD_SET_E_BITS 0x04
#define ZX_GS_CMD_OUT_VOLUME_PORT 0x05
#define ZX_GS_CMD_SEND_TO_DAC 0x06
#define ZX_GS_CMD_SEND_TO_DAC_AND_VOLUME 0x07
#define ZX_GS_CMD_RESET_FLAGS2 0x08
#define ZX_GS_CMD_SEND_ONE_BYTE_VOLUME 0x09
#define ZX_GS_CMD_DAC_OUT 0x0A
#define ZX_GS_CMD_DAC_AND_VOLUME_OUT 0x0B
#define ZX_GS_CMD_CALL_SOUNDRIVE_MODE 0x0C
#define ZX_GS_CMD_CALL_ULTRAVOX_MODE 0x0D
#define ZX_GS_CMD_COVOX_MODE 0x0E
#define ZX_GS_CMD_PROFI_COVOX_MODE 0x0F
#define ZX_GS_CMD_OUT_TO_ANY_PORT 0x10
#define ZX_GS_CMD_IN_FROM_ANY_PORT 0x11
#define ZX_GS_CMD_OUT_TO_ZERO_PORT 0x12
#define ZX_GS_CMD_JUMP_TO_ADDR 0x13
#define ZX_GS_CMD_LOAD_MEMORY_BLOCK 0x14
#define ZX_GS_CMD_GET_MEMORY_BLOCK 0x15
#define ZX_GS_CMD_POKE_TO_ADDR 0x16
#define ZX_GS_CMD_PEEK_FROM_ADDR 0x17
#define ZX_GS_CMD_LOAD_DE_PAIR 0x18
#define ZX_GS_CMD_POKE_TO_DE_ADDR 0x19
#define ZX_GS_CMD_PEEK_FROM_DE_ADDR 0x1A
#define ZX_GS_CMD_INCREMENT_DE 0x1B
#define ZX_GS_CMD_POKE_TO_20XX_ADDR 0x1C
#define ZX_GS_CMD_PEEK_FROM_20XX_ADDR 0x1D
#define ZX_GS_CMD_GET_TOTAL_RAM 0x20
#define ZX_GS_CMD_GET_FREE_RAM 0x21
#define ZX_GS_CMD_GET_GS_VARIABLE 0x22
#define ZX_GS_CMD_GET_RAM_PAGES 0x23
#define ZX_GS_CMD_SET_MODULE_MASTER_VOLUME 0x2A
#define ZX_GS_CMD_SET_FX_MASTER_VOLUME 0x2B
#define ZX_GS_CMD_SET_CURRENT_FX 0x2E
#define ZX_GS_CMD_LOAD_MODULE 0x30
#define ZX_GS_CMD_PLAY_MODULE 0x31
#define ZX_GS_CMD_STOP_MODULE 0x32
#define ZX_GS_CMD_CONTINUE_MODULE 0x33
#define ZX_GS_CMD_SET_MODULE_VOLUME 0x35
#define ZX_GS_CMD_DATA_ON 0x36
#define ZX_GS_CMD_REINITIALISATION 0x37
#define ZX_GS_CMD_LOAD_FX 0x38
#define ZX_GS_CMD_PLAY_FX 0x39
#define ZX_GS_CMD_STOP_FX_CHANNELS 0x3A
#define ZX_GS_CMD_SET_FX_VOLUME 0x3D
#define ZX_GS_CMD_LOAD_FX_SIGNED 0x3E
#define ZX_GS_CMD_SET_FX_NOTE 0x40
#define ZX_GS_CMD_SET_FX_SAMPLE_VOLUME 0x41
#define ZX_GS_CMD_SET_FX_SAMPLE_FINETUNE 0x42
#define ZX_GS_CMD_SET_FX_PRIORITY 0x45
#define ZX_GS_CMD_SET_FX_SEEK_FIRST 0x46
#define ZX_GS_CMD_SET_FX_SEEK_LAST 0x47
#define ZX_GS_CMD_SET_FX_LOOP_BEGIN 0x48
#define ZX_GS_CMD_SET_FX_LOOP_END 0x49
#define ZX_GS_CMD_GET_SONG_POSITION 0x60
#define ZX_GS_CMD_GET_PATTERN_POSITION 0x61
#define ZX_GS_CMD_GET_MIXED_POSITION 0x62
#define ZX_GS_CMD_GET_CHANNEL_NOTES 0x63
#define ZX_GS_CMD_GET_CHANNEL_VOLUMES 0x64
#define ZX_GS_CMD_JUMP_TO_POSITION 0x65
#define ZX_GS_CMD_SET_SPEED_N_TEMPO 0x66
#define ZX_GS_CMD_GET_SPEED_VALUE 0x67
#define ZX_GS_CMD_GET_TEMPO_VALUE 0x68
#define ZX_GS_CMD_PROCESS_SOUND 0x69
#define ZX_GS_CMD_DIRECT_PLAY_FX_BASE 0x80
#define ZX_GS_CMD_DIRECT_PLAY_FX_NOTE_BASE 0x88
#define ZX_GS_CMD_DIRECT_PLAY_FX_VOL_BASE 0x90
#define ZX_GS_CMD_DIRECT_PLAY_FX_FULL_BASE 0x98
#define ZX_GS_CMD_CHANGE_CHANNEL_NOTE 0xA0
#define ZX_GS_CMD_CHANGE_CHANNEL_VOLUME 0xA8
#define ZX_GS_CMD_OPEN_STREAM 0xD1
#define ZX_GS_CMD_CLOSE_STREAM 0xD2
#define ZX_GS_CMD_WARM_RESTART 0xF3
#define ZX_GS_CMD_COLD_RESTART 0xF4
#define ZX_GS_CMD_BUSY_ON 0xF5
#define ZX_GS_CMD_BUSY_OFF 0xF6
#define ZX_GS_CMD_GET_HX_REG 0xF7
#define ZX_GS_CMD_OUT_ZERO_TO_ZERO 0xFA
#define ZX_GS_CMD_ENTER_TEST_MODE 0xFA

// Status register bits
#define ZX_GS_STATUS_DATA_BIT 0x80
#define ZX_GS_STATUS_COMMAND_BIT 0x01

// Volume range
#define ZX_GS_VOLUME_MIN 0x00
#define ZX_GS_VOLUME_MAX 0x40

// Note range
#define ZX_GS_NOTE_MIN 0
#define ZX_GS_NOTE_MAX 95

// Channel mask for all channels
#define ZX_GS_CHANNEL_MASK_ALL 0xFF

// Port definitions
static __sfr __at ZX_GS_COMMAND_REGISTER_PORT zx_gs_command_register;
static __sfr __at ZX_GS_STATUS_REGISTER_PORT zx_gs_status_register;
static __sfr __at ZX_GS_DATA_REGISTER_PORT zx_gs_data_register;
static __sfr __at ZX_GS_OUTPUT_REGISTER_PORT zx_gs_output_register;

// Wait functions
#define ZX_GS_wait_command_ready()                                  \
	while ((zx_gs_status_register & ZX_GS_STATUS_COMMAND_BIT) != 0) { \
	}
#define ZX_GS_wait_data_ready()                                  \
	while ((zx_gs_status_register & ZX_GS_STATUS_DATA_BIT) != 0) { \
	}
#define ZX_GS_wait_data_available()                              \
	while ((zx_gs_status_register & ZX_GS_STATUS_DATA_BIT) == 0) { \
	}

// Basic control functions

/**
 * @brief Reset flags
 *  Сбрасывает флаги Data bit и Command bit.
 */
void ZX_GS_reset_flags(void);

/**
 * @brief Warm restart
 *  Сбрасывает полностью GS, но пропускает этапы определения количества страниц памяти и их провеки,
 *  что очень сильно ускоряет процесс инициализации.
 */
void ZX_GS_warm_restart(void);

/**
 * @brief Cold restart
 *  Полный перезапуск GS со всеми провер-ками. По сути, JP #0000.
 */
void ZX_GS_cold_restart(void);

// Memory information functions

/**
 * @brief Get total RAM
 *  Получить общий объем доступной памяти на  GS. ( В базовой версии это 112к)
 */
uint32_t ZX_GS_get_total_ram(void);

/**
 * @brief Get free RAM
 *  Получить общий объем свободной памяти на  GS.
 */
uint32_t ZX_GS_get_free_ram(void);

/**
 * @brief Get number of RAM Pages
 *  Получить число страниц на  GS.
 */
uint8_t ZX_GS_get_ram_pages(void);

// Volume control functions

/**
 * @brief Set Module Master Volume
 *  Установить громкость проигрывания модулей.
 */
uint8_t ZX_GS_set_module_master_volume(uint8_t volume);

/**
 * @brief Set FX Master Volume
 *  Установить громкость проигрывания эффектов.
 */
uint8_t ZX_GS_set_fx_master_volume(uint8_t volume);

/**
 * @brief Set Module Volume
 *  Установить громкость проигрывания модулей.
 */
uint8_t ZX_GS_set_module_volume(uint8_t volume);

// Basic sound control functions

/**
 * @brief Set silence
 *  Выводит в ЦАПы всех каналов #80. По сути устанавливает тишину.
 */
void ZX_GS_set_silence(void);

/**
 * @brief Set low volume
 *  Устанавливает громкость ЦАПов всех каналов в ноль.
 */
void ZX_GS_set_low_volume(void);

/**
 * @brief Set high volume
 *  Устанавливает громкость ЦАПов всех каналов в максимум.
 */
void ZX_GS_set_high_volume(void);

/**
 * @brief Set 'E' 3bits
 *  Устанавливает в 'E' регистре GS 3 младших бита в соответствии с заданным значением.
 */
void ZX_GS_set_e_bits(uint8_t chan);

/**
 * @brief Out volume port
 *  Устанавливает громкость канала, номер которого содержится в 'E', в указанное значение.
 */
void ZX_GS_out_volume_port(uint8_t volume);

/**
 * @brief Send to DAC
 *  Выводит байт в ЦАП канала, указываемого по 'E'.
 */
void ZX_GS_send_to_dac(uint8_t byte);

/**
 * @brief Send to DAC and to volume port
 *  Выводит байт в ЦАП ('E') с заданной громкостью.
 */
void ZX_GS_send_to_dac_and_volume(uint8_t byte, uint8_t volume);

/**
 * @brief Send one's byte volume
 *  Установка громкости канала, номер которого задан в 2х старших битах.
 */
void ZX_GS_send_one_byte_volume(uint8_t byte);

/**
 * @brief DAC output
 *  Еще один непосредственный вывод в ЦАП.
 */
void ZX_GS_dac_out(uint8_t byte, uint8_t chan);

/**
 * @brief DAC and Volume output
 *  И наконец последний вывод в ЦАП с установкой громкости.
 */
void ZX_GS_dac_and_volume_out(uint8_t fbyte, uint8_t sbyte);

// FX management functions

/**
 * @brief Set Current FX
 *  Установить   текущий   эффект.  Просто присваивает  переменной CURFX это значение.
 *  Если какая-либо команда требует номер сэмпла (sample handle), то можно
 *  вместо  этого  номера  подать ей #00 и интерпретатор  подставит  вместо этого
 *  нуля  значение  переменной CURFX.
 */
void ZX_GS_set_current_fx(uint8_t fx_handle);

// Module control functions

/**
 * @brief Load Module
 *  Загрузка модуля в память.
 */
uint8_t ZX_GS_load_module_start(void);

void ZX_GS_load_module_data(uint8_t *data, uint16_t size);

void ZX_GS_load_module_end(void);

/**
 * @brief Play module
 *  Проигрывание модуля.
 */
void ZX_GS_play_module(uint8_t module_handle);

/**
 * @brief Stop module
 *  Остановить проигрывание модуля.
 */
void ZX_GS_stop_module(void);

/**
 * @brief Continue module
 *  Продолжить проигрывание модуля после остановки.
 */
void ZX_GS_continue_module(void);

// FX loading functions

/**
 * @brief Load FX
 *  Загрузка сэмпла эффекта в память.
 *  Загружает беззнаковые сэмплы
 *  (PC type)
 */
uint8_t ZX_GS_load_fx_unsigned_start(void);

/**
 * @brief Load FX (Extended version)
 *  Загрузка сэмпла эффекта в память.
 *  Позволяет загружать сэмплы со знаком.
 *  (Amiga type)
 */
uint8_t ZX_GS_load_fx_signed_start(void);

void ZX_GS_load_fx_data(uint8_t *data, uint16_t size);

void ZX_GS_load_fx_end(void);

// FX playback functions

/**
 * @brief Play FX
 *  Проигрывание эффекта.
 */
void ZX_GS_play_fx(uint8_t fx_handle);

/**
 * @brief Stop FX in channels
 *  Остановка проигрывания эффектов в заданных каналах, которые указываются в маске каналов (Channel Mask).
 *  В ней единица в n-ном бите указывает на то, что эффект в n-ном канале требуется остановить
 */
void ZX_GS_stop_fx_channels(uint8_t channel_mask);

// FX parameter setting functions

/**
 * @brief Set FX Sample Playing Note
 *  Установка ноты по умолчанию для текущего эффекта.
 */
void ZX_GS_set_fx_note(uint8_t note);

/**
 * @brief Set FX Sample Volume
 *  Установка громкости по умолчанию для текущего эффекта.
 */
void ZX_GS_set_fx_sample_volume(uint8_t volume);

/**
 * @brief Set FX Sample Priority
 *  Установка приоритета для текущего эффекта.
 */
void ZX_GS_set_fx_priority(uint8_t priority);

/**
 * @brief Set FX Sample Seek First parameter
 *  Установка параметра Seek First для текущего эффекта.
 */
void ZX_GS_set_fx_seek_first(uint8_t seek_first);

/**
 * @brief Set FX Sample Seek Last parameter
 *  Установка параметра Seek Last для текущего эффекта.
 */
void ZX_GS_set_fx_seek_last(uint8_t seek_last);

// Position information functions

/**
 * @brief Get Song Position
 *  Получение значения переменной Song_Position в текущем модуле.
 */
uint8_t ZX_GS_get_song_position(void);

/**
 * @brief Get Pattern Position
 *  Получение значения переменной Pattern_Position в текущем модуле.
 */
uint8_t ZX_GS_get_pattern_position(void);

/**
 * @brief Get Mixed Position
 *  Получить значение Pattern_Position, немного смешанной с Song_Position.
 */
uint8_t ZX_GS_get_mixed_position(void);

// Channel information functions

/**
 * @brief Get Channel Notes
 *  Получить ноты всех каналов модуля.
 */
void ZX_GS_get_channel_notes(uint8_t *notes);

/**
 * @brief Get Channel Volumes
 *  Получить громкости всех каналов модуля.
 */
void ZX_GS_get_channel_volumes(uint8_t *volumes);

// Direct play FX functions

/**
 * @brief Direct Play FX Sample (#80..#83)
 *  Проигрывание сэмпла в заданном канале.
 */
void ZX_GS_direct_play_fx(uint8_t channel, uint8_t sample_number);

/**
 * @brief Direct Play FX Sample (#88..#8B)
 *  Проигрывание  сэмпла в заданном канале с заданной нотой.
 */
void ZX_GS_direct_play_fx_note(uint8_t channel, uint8_t sample_number, uint8_t note);

/**
 * @brief Direct Play FX Sample (#90..#93)
 *  Проигрывание  сэмпла в заданном канале с заданной громкостью.
 */
void ZX_GS_direct_play_fx_volume(uint8_t channel, uint8_t sample_number, uint8_t volume);

/**
 * @brief Direct Play FX Sample (#98..#9B)
 *  Проигрывание сэмпла в заданном канале с заданной нотой и громкостью.
 */
void ZX_GS_direct_play_fx_full(uint8_t channel, uint8_t sample_number, uint8_t note, uint8_t volume);

// Covox mode functions

/**
 * @brief Go in Covox mode Переходит в режим Ковокс,
 *  напрямую копирует регистр данных в ЦАПы двух (правого и левого) каналов.
 *  Выход из этого режима - запись #00 в регистр команд.
 */
void ZX_GS_enter_covox_mode(void);

void ZX_GS_covox_output(uint8_t left, uint8_t right);

void ZX_GS_exit_covox_mode(void);

// Covox mode functions (extended)

/**
 * @brief Call SounDrive Covox mode
 *  Вызывает режим четырехканального Ковокса, последовательно копирует регистр данных по каналам.
 */
void ZX_GS_call_sounddrive_mode(uint8_t ch1, uint8_t ch2, uint8_t ch3, uint8_t ch4);

/**
 * @brief Call Ultravox mode
 *  Вызывает режим универсального Ковокса, последовательно копирует регистр данных по каналам.
 */
void ZX_GS_call_ultravox_mode(uint8_t chans, uint8_t ch1, uint8_t ch2, uint8_t ch3, uint8_t ch4);

/**
 * @brief Go in Profi Covox mode
 *  Переходит в режим двухканального Ковокса, напрямую копирует регистр данных в ЦАПы одного канала.
 */
void ZX_GS_enter_profi_covox_mode(void);

void ZX_GS_profi_covox_output(uint8_t data_byte, uint8_t command_byte);

void ZX_GS_exit_profi_covox_mode(void);

// Port and memory functions

/**
 * @brief Out to any port
 *  Выводит байт вo внутренний порт GS (#00-#09).
 */
void ZX_GS_out_to_any_port(uint8_t port, uint8_t data);

/**
 * @brief In from any port
 *  Читает байт из внутреннего порта GS (#00-#09).
 */
uint8_t ZX_GS_in_from_any_port(uint8_t port);

/**
 * @brief OUT to 0 port
 *  Выводит байт в порт конфигурации GS (#00).
 */
void ZX_GS_out_to_zero_port(uint8_t data);

/**
 * @brief Jump to Address
 *  Передает управление по заданному адресу.
 */
void ZX_GS_jump_to_addr(uint16_t addr);

/**
 * @brief Load memory block
 *  Загрузка блока кодов по указанному адресу с заданной длиной.
 */
void ZX_GS_load_memory_block(uint16_t addr, uint8_t *data, uint16_t len);

/**
 * @brief Get memory block
 *  Выгрузка блока кодов по указанному адресу с заданной длиной.
 */
void ZX_GS_get_memory_block(uint16_t addr, uint8_t *data, uint16_t len);

/**
 * @brief Poke to address
 *  Записывает единичный байт по указанному адресу.
 */
void ZX_GS_poke_to_addr(uint8_t byte, uint16_t addr);

/**
 * @brief Peek from address
 *  Считывает единичный байт из указанного адреса.
 */
uint8_t ZX_GS_peek_from_addr(uint16_t addr);

/**
 * @brief Load DE Pair
 *  Загружает регистровую пару DE указанным словом.
 */
void ZX_GS_load_de_pair(uint16_t value);

/**
 * @brief Poke to (DE) address
 *  Записывает байт по адресу указанному в DE.
 */
void ZX_GS_poke_to_de_addr(uint8_t byte);

/**
 * @brief Peek from (DE) address
 *  Считывает содержимое адреса, указываемого по DE.
 */
uint8_t ZX_GS_peek_from_de_addr(void);

/**
 * @brief Increment of DE Pair
 *  Увеличивает пару DE на единичку.
 */
void ZX_GS_increment_de(void);

/**
 * @brief Poke to (#20XX) address
 *  Записывает байт по адресу, старший байт которого равен #20.
 */
void ZX_GS_poke_to_20xx_addr(uint8_t addr_l, uint8_t byte);

/**
 * @brief Peek from (#20XX) address
 *  Читает байт с адреса, старший байт которого равен #20.
 */
uint8_t ZX_GS_peek_from_20xx_addr(uint8_t addr_l);

// Busy control functions

/**
 * @brief Busy on
 *  Устанавливает флаг занятости в #FF
 */
void ZX_GS_busy_on(void);

/**
 * @brief Busy off
 *  Устанавливает флаг занятости в #00
 */
void ZX_GS_busy_off(void);

/**
 * @brief Get HX Register
 *  Получить содержимое регистра HX (GS).
 */
uint8_t ZX_GS_get_hx_reg(void);

/**
 * @brief Out zero_to_zero
 *  Вывод нуля в нулевой (конфигурационный) порт GS.
 */
void ZX_GS_out_zero_to_zero(void);

// Additional FX parameter functions

/**
 * @brief Set FX Sample Finetune
 *  Установка Finetune по умолчанию для текущего эффекта.
 */
void ZX_GS_set_fx_sample_finetune(uint8_t finetune);

/**
 * @brief Set FX Sample Loop Begin
 *  Установка начала цикла для текущего эффекта.
 */
void ZX_GS_set_fx_loop_begin(uint32_t len);

/**
 * @brief Set FX Sample Loop End
 *  Установка конца цикла для текущего эффекта.
 */
void ZX_GS_set_fx_loop_end(uint32_t len);

// Module control functions (extended)

/**
 * @brief Jump to position
 *  Делает переход на заданную позицию.
 */
void ZX_GS_jump_to_position(uint8_t position);

/**
 * @brief Set speed/tempo
 *  Установка скорости в пределах #01-#1F. При значениях #20-#FF устанавливается темп проигрывания.
 */
void ZX_GS_set_speed_tempo(uint8_t speed_tempo);

/**
 * @brief Get speed value
 *  Чтение текущей скорости.
 */
uint8_t ZX_GS_get_speed_value(void);

/**
 * @brief Get tempo value
 *  Чтение текущего темпа.
 */
uint8_t ZX_GS_get_tempo_value(void);

/**
 * @brief Process Sound
 *  Переход на следующий кварк (или тик) в процессе проигрывания звука.
 */
void ZX_GS_process_sound(void);

// Channel control functions

/**
 * @brief Change Channel Note
 *  Смена текущей ноты в заданном канале. Производится «на лету».
 */
void ZX_GS_change_channel_note(uint8_t channel, uint8_t note);

/**
 * @brief Change Channel Volume
 *  Подобно предыдущей команде «на лету» меняет громкость канала.
 */
void ZX_GS_change_channel_volume(uint8_t channel, uint8_t volume);

#endif // ZX_GS_H
