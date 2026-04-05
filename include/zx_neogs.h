/**
 * @file zx_neogs.h
 * @brief Библиотека функций для работы с NeoGS
 *
 * Данная библиотека предоставляет функции NeoGS, расширяющие возможности обычного General Sound (описан в файле zx_gs.h)
 *
 * Часть функций библиотеки требует доработки и отладки
 *
 * Автор: Dmitry Panin UA3REO
 * Компилятор: SDCC
 * Целевая платформа: ZX Spectrum
 */

#ifndef ZX_NEOGS_H
#define ZX_NEOGS_H

#include "zx.h"
#include "zx_gs.h"
#include <stdint.h>

// ZX-Side NeoGS Ports
#define ZX_NEOGS_CONTROL_REGISTER_PORT 0x33

// NeoGS Control commands
#define ZX_NEOGS_CONTROL_CMD_RESET 0x80
#define ZX_NEOGS_CONTROL_CMD_NMI 0x40
#define ZX_NEOGS_CONTROL_CMD_LED 0x20

// NeoGS-Side Ports
#define ZX_NEOGS_INNER_PORT_MEM_PAGE 0x00          // MPAG write-only, Memory PAGe port (big pages at 8000-FFFF or small at 8000-BFFF)
#define ZX_NEOGS_INNER_PORT_ZX_COMMAND 0x01        // ZXCMD read-only, ZX CoMmanD port: here is the byte written by ZX into GSCOM
#define ZX_NEOGS_INNER_PORT_LED_CONTROL 0x01       // LEDCTR write-only, controls on-board LED. D0=0 - LED is on, D0=1 - LED is off reset state is LED on.
#define ZX_NEOGS_INNER_PORT_ZX_DATA_READ 0x02      // ZXDATRD read-only, ZX DATa ReaD: a byte written by ZX into GSDAT appears here; upon reading this port, data bit is cleared
#define ZX_NEOGS_INNER_PORT_ZX_DATA_WRITE 0x03     // ZXDATWR write-only, ZX DATa WRite: a byte written here is available for ZX in GSDAT; upon writing here, data bit is set
#define ZX_NEOGS_INNER_PORT_ZX_STATUS 0x04         // ZXSTAT read-only, read ZX STATus: command and data bits. positions are defined by *_CBIT and *_DBIT above
#define ZX_NEOGS_INNER_PORT_CLEAR_COMMAND_BIT 0x05 // CLRCBIT read-write, upon either reading or writing this port, the Command BIT is CLeaRed
#define ZX_NEOGS_INNER_PORT_VOLUME_1 0x06          // VOL1 write-only, volumes for sound channel 1
#define ZX_NEOGS_INNER_PORT_VOLUME_2 0x07          // VOL2 write-only, volumes for sound channel 2
#define ZX_NEOGS_INNER_PORT_VOLUME_3 0x08          // VOL3 write-only, volumes for sound channel 3
#define ZX_NEOGS_INNER_PORT_VOLUME_4 0x09          // VOL4 write-only, volumes for sound channel 4
#define ZX_NEOGS_INNER_PORT_DAMNPORT1 0x0A         // writing or reading this port sets data bit to the inverse of bit 0 into MPAG port
#define ZX_NEOGS_INNER_PORT_DAMNPORT2 0x0B         // the same as DAMNPORT1, but instead command bit involved, which is made equal to 5th bit of VOL4
#define ZX_NEOGS_INNER_PORT_INT_ENABLED 0x0C       // INTENA interrupt enables
#define ZX_NEOGS_INNER_PORT_INT_REQUESTS 0x0D      // INTREQ interrupt requests
#define ZX_NEOGS_INNER_PORT_TIMER_FREQUENCY 0x0E   // timer frequency
#define ZX_NEOGS_INNER_PORT_CONFIG0 0x0F           // GSCFG0 read-write, GS ConFiG port 0: acts as memory cell, reads previously written value
#define ZX_NEOGS_INNER_PORT_MEM_PAGE_EXT 0x10      // MPAGEX write-only, Memory PAGe EXtended (only small pages at C000-FFFF)
#define ZX_NEOGS_INNER_PORT_SERIAL_CONTROL 0x11    // SCTRL Serial ConTRoL: read-write, read: current state of below bits, write - see GS_info
#define ZX_NEOGS_INNER_PORT_SERIAL_STATUS 0x12     // SSTAT Serial STATus: read-only, reads state of below bits
#define ZX_NEOGS_INNER_PORT_SD_SEND 0x13           // SD_SEND SD card SEND, write-only, when written, byte transfer starts with written byte
#define ZX_NEOGS_INNER_PORT_SD_READ 0x13           // SD_READ SD card READ, read-only, reads byte received in previous byte transfer
#define ZX_NEOGS_INNER_PORT_SD_READ_N_START 0x14   // SD_RSTR SD card Read and STaRt, read-only, reads previously received byte and starts new byte transfer with #FF
#define ZX_NEOGS_INNER_PORT_MD_SEND 0x14           // MD_SEND Mp3 Data SEND, write-only, sends byte to the mp3 data interface
#define ZX_NEOGS_INNER_PORT_MC_SEND 0x15           // MC_SEND Mp3 Control SEND, write-only, sends byte to the mp3 control interface
#define ZX_NEOGS_INNER_PORT_MC_READ 0x15           // MC_READ Mp3 Control READ, read-only, reads byte that was received during previous sending of byte
#define ZX_NEOGS_INNER_PORT_VOLUME_5 0x16          // VOL5 write-only, volumes for sound channel 5
#define ZX_NEOGS_INNER_PORT_VOLUME_6 0x17          // VOL6 write-only, volumes for sound channel 6
#define ZX_NEOGS_INNER_PORT_VOLUME_7 0x18          // VOL7 write-only, volumes for sound channel 7
#define ZX_NEOGS_INNER_PORT_VOLUME_8 0x19          // VOL8 write-only, volumes for sound channel 8
#define ZX_NEOGS_INNER_PORT_DMA_MODULE 0x1B        // DMA_MOD select DMA module to work with via DMA_HAD, DMA_MAD, DMA_LAD, DMA_CST ports
#define ZX_NEOGS_INNER_PORT_DMA_HIGH 0x1C          // DMA_HAD High DMA ADdress (bits 21:16)
#define ZX_NEOGS_INNER_PORT_DMA_MID 0x1D           // DMA_MAD Middle DMA ADdress (bits 15:8)
#define ZX_NEOGS_INNER_PORT_DMA_LOW 0x1E           // DMA_LAD Low  DMA ADdress (bits  7:0)
#define ZX_NEOGS_INNER_PORT_DMA_CONTROL_STATE 0x1F // DMA_CST DMA Control and STate
#define ZX_NEOGS_INNER_PORT_RAM_WINDOW_0 0x20      // 0000-3fff 16k page (0..255 -- 0..4Mb)
#define ZX_NEOGS_INNER_PORT_RAM_WINDOW_1 0x21      // 4000-7fff
#define ZX_NEOGS_INNER_PORT_RAM_WINDOW_2 0x22      // 8000-bfff
#define ZX_NEOGS_INNER_PORT_RAM_WINDOW_3 0x23      // c000-ffff

// Masks for ZX_NEOGS_INNER_PORT_CONFIG0
#define ZX_NEOGS_CONFIG_NO_ROM_MASK 0x01          // =0 - there is ROM everywhere except 4000-7FFF, =1 - the RAM is all around
#define ZX_NEOGS_CONFIG_ROM_RO_MASK 0x02          // =1 - ram absolute addresses 0000-7FFF (zeroth big page) are write-protected
#define ZX_NEOGS_CONFIG_8_CHANNELS_MASK 0x04      // =1 - 8 channels mode
#define ZX_NEOGS_CONFIG_ENTENDED_PAGING_MASK 0x08 // =1 - extended paging: both MPAG and MPAGEX are used to switch two memory windows
#define ZX_NEOGS_CONFIG_CLOCK_SEL_0 0x10          // these bits should be set according to the C_**MHZ constants below
#define ZX_NEOGS_CONFIG_CLOCK_SEL_1 0x20          // these bits should be set according to the C_**MHZ constants below
#define ZX_NEOGS_CONFIG_CHANNELS_PANNING 0x40     // =1 - 4 channels, panning (every channel is on left and right with two volumes)
#define ZX_NEOGS_CONFIG_INVERT_7BIT 0x80          // =1 - invert 7th bit of samples before putting them to MUL/DAC
#define ZX_NEOGS_CONFIG_CPU_SPEED_MASK 0x30
#define ZX_NEOGS_CONFIG_CPU_10MHZ 0x30
#define ZX_NEOGS_CONFIG_CPU_12MHZ 0x10
#define ZX_NEOGS_CONFIG_CPU_20MHZ 0x20
#define ZX_NEOGS_CONFIG_CPU_24MHZ 0x00

// Masks for ZX_NEOGS_INNER_PORT_SERIAL_CONTROL
#define ZX_NEOGS_SERIAL_SD_NCS_MASK 0x01  // Бит управления сигналом nCS для SD-карты
#define ZX_NEOGS_SERIAL_MC_NCS_MASK 0x02  // Бит управления сигналом nCS для MP3-декодера
#define ZX_NEOGS_SERIAL_MC_XRS_MASK 0x04  // Выходной сигнал аппаратного сброса на MP3-декодер, активный уровень низкий.
#define ZX_NEOGS_SERIAL_MC_SPD0_MASK 0x08 // Биты установки частоты Fsck управляющего интерфейса MP3-декодера
#define ZX_NEOGS_SERIAL_MD_HLF_MASK 0x10  // Бит установки частоты Fsck интерфейса данных
#define ZX_NEOGS_SERIAL_MC_SPD1_MASK 0x20 // Биты установки частоты Fsck управляющего интерфейса MP3-декодера

// Helper
/** Для установки какого-либо отдельного бита в 1 в порт SCTRL записывается число
 *  (1<<B_SETNCLR)+(1<<B_bit), где B_bit - один из вышеперечисленных битов порта
 *  SCTRL, а B_SETNCLR - служебный бит этого порта. Для установки отдельного бита в 0 в
 *  порт записывается число (0<<B_SETNCLR)+(1<<B_bit).
 *  Данным способом одновременно перевести в 1 либо в 0 можно сразу несколько бит, для
 *  чего следует набрать их маску в записываемом числе, а состояние бита B_SETNCLR в
 *  записываемом числе определяет, в какое состояние (0 или 1) устанавливается выбранный набор.
 */
#define ZX_NEOGS_SET_N_CLR_BIT 7
#define ZX_NEOGS_SET_N_CLR_MASK 0x80

// Masks for ZX_NEOGS_INNER_PORT_SERIAL_STATUS
#define ZX_NEOGS_SERIAL_MD_DRQ_MASK 0x01 // Входной сигнал готовности принимать данные, поступающий с MP3-декодера
#define ZX_NEOGS_SERIAL_SD_DET_MASK 0x02 // Установлен в 0 при отсутствии SD-карты
#define ZX_NEOGS_SERIAL_SD_WP_MASK 0x04  // Установлен в 1 при флажке в положении «защита записи»
#define ZX_NEOGS_SERIAL_MC_RDY_MASK 0x08 // Бит готовности SPI-интерфейса в порту управляющего интерфейса MP3-декодера

// Values for ZX_NEOGS_INNER_PORT_DMA_MODULE
#define ZX_NEOGS_DMA_NONE 0x00 // none selected
#define ZX_NEOGS_DMA_ZX 0x01   // ZX module selected
#define ZX_NEOGS_DMA_SD 0x01   // SD module selected
#define ZX_NEOGS_DMA_MP3 0x01  // MP3 module selected

// Values for ZX_NEOGS_INNER_PORT_TIMER_FREQUENCY
#define ZX_NEOGS_TIMER_DEFAULT 0x00 // default 37500 Hz (after reset)
#define ZX_NEOGS_TIMER_DIV2 0x01    // 18750 Hz (div by 2)
#define ZX_NEOGS_TIMER_DIV4 0x02    // 9375 Hz (div by 4)
#define ZX_NEOGS_TIMER_DIV8 0x03    // etc...
#define ZX_NEOGS_TIMER_DIV16 0x04
#define ZX_NEOGS_TIMER_DIV64 0x05
#define ZX_NEOGS_TIMER_DIV256 0x06
#define ZX_NEOGS_TIMER_DIV1024 0x07

// Masks for ZX_NEOGS_INNER_PORT_INT_ENABLED & ZX_NEOGS_INNER_PORT_INT_REQUESTS
#define ZX_NEOGS_INT_TIMER_MASK 0x01
#define ZX_NEOGS_INT_SD_DMA_MASK 0x02
#define ZX_NEOGS_INT_MP3_DMA_MASK 0x04
#define ZX_NEOGS_INT_SETNCLR_MASK 0x80

// MP3 Player Commands
#define ZX_NEOGS_MP3_CMD_BASE 0x1F
#define ZX_NEOGS_MP3_DATA_INIT 0x60
#define ZX_NEOGS_MP3_DATA_RESTART 0x00
#define ZX_NEOGS_MP3_DATA_PLAY 0x02
#define ZX_NEOGS_MP3_DATA_PAUSE 0x03
#define ZX_NEOGS_MP3_DATA_STOP 0x04
#define ZX_NEOGS_MP3_DATA_PREV_TRACK 0x01
#define ZX_NEOGS_MP3_DATA_NEXT_TRACK 0x05
#define ZX_NEOGS_MP3_DATA_TOGGLE_TREBLE_BASS 0x06
#define ZX_NEOGS_MP3_DATA_TOGGLE_SURROUND 0x07
#define ZX_NEOGS_MP3_DATA_VOLUME_UP 0x08
#define ZX_NEOGS_MP3_DATA_VOLUME_DOWN 0x09
#define ZX_NEOGS_MP3_DATA_TOGGLE_MUTE 0x0A
#define ZX_NEOGS_MP3_DATA_GET_TIME_TEXT 0x0B
#define ZX_NEOGS_MP3_DATA_GET_STATUS 0x0C
#define ZX_NEOGS_MP3_DATA_GET_CURRENT_FILE 0x0D
#define ZX_NEOGS_MP3_DATA_SET_FILE 0x0E
#define ZX_NEOGS_MP3_DATA_TOGGLE_RESET_MODE 0x0F
#define ZX_NEOGS_MP3_DATA_GET_FAT_TYPE 0x10
#define ZX_NEOGS_MP3_DATA_GET_FILE_INFO 0x11
#define ZX_NEOGS_MP3_DATA_GET_FILE_ENTRY 0x12
#define ZX_NEOGS_MP3_DATA_GET_FILES_COUNT 0x13
#define ZX_NEOGS_MP3_DATA_SEND_512_BYTES 0x14
#define ZX_NEOGS_MP3_DATA_GET_FILES_COUNT_TEXT 0x15
#define ZX_NEOGS_MP3_DATA_GET_NEXT_FILE_TEXT 0x16
#define ZX_NEOGS_MP3_DATA_SET_RESET_MODE 0x17
#define ZX_NEOGS_MP3_DATA_PREV_DIRECTORY 0x18
#define ZX_NEOGS_MP3_DATA_NEXT_DIRECTORY 0x19
#define ZX_NEOGS_MP3_DATA_SET_TONE_CONTROL 0x1A
#define ZX_NEOGS_MP3_DATA_GET_TONE_POSITION 0x1B
#define ZX_NEOGS_MP3_DATA_GET_CURRENT_FILE_INFO 0x1C
#define ZX_NEOGS_MP3_DATA_CHECK 0x00

// Bootloader Commands
#define ZX_NEOGS_BOOTLOADER_CMD_LOAD_FIRMWARE_FROM_SPECTRUM 0x00
#define ZX_NEOGS_BOOTLOADER_CMD_RUN_FIRMWARE 0x01
#define ZX_NEOGS_BOOTLOADER_CMD_RUN_ROM_FIRMWARE 0x02
#define ZX_NEOGS_BOOTLOADER_CMD_RUN_SD_FIRMWARE 0x03
#define ZX_NEOGS_BOOTLOADER_CMD_LOAD_CODE_FROM_SPECTRUM 0x04
#define ZX_NEOGS_BOOTLOADER_CMD_LOAD_FILE_FROM_SD 0x05
#define ZX_NEOGS_BOOTLOADER_CMD_RUN_CODE 0x06
#define ZX_NEOGS_BOOTLOADER_CMD_GET_FILE_STATUS 0x07
#define ZX_NEOGS_BOOTLOADER_CMD_GET_PAGE_VERSION 0x08
#define ZX_NEOGS_BOOTLOADER_CMD_GET_CRC_INFO 0x09
#define ZX_NEOGS_BOOTLOADER_CMD_LOAD_UPDATE_FILE 0x0A
#define ZX_NEOGS_BOOTLOADER_CMD_SET_GET_CPU_FREQUENCY 0x0B
#define ZX_NEOGS_BOOTLOADER_CMD_CHECK_BOOTLOADER 0x1D
#define ZX_NEOGS_BOOTLOADER_DATA_CHECK 0x00
#define ZX_NEOGS_BOOTLOADER_CPU_FREQ_GET 0x80

// Port definitions
static __sfr __at ZX_NEOGS_CONTROL_REGISTER_PORT zx_neogs_control_register;

/**
 * @brief происходит 'тёплый' сброс процессора и железа NeoGS (без перезагрузки прошивки FPGA)
 */
void ZX_NEOGS_reset(void);

/**
 * @brief на процессор NeoGS выдаётся запрос немаскируемого прерывания /NMI
 */
void ZX_NEOGS_NMI(void);

/**
 * @brief светодиод на плате NeoGS меняет своё состояние (горит-не горит)
 */
void ZX_NEOGS_toggle_LED(void);

/**
 * @brief Управление процессором NeoGS
 */
void ZX_NEOGS_set_CPU_speed(uint8_t mask);

/**
 * @brief Установка страницы памяти в область $8000-$FFFF
 * @param page_num Номер страницы (0-63)
 */
void ZX_NEOGS_set_memory_page(uint8_t page_num);

/**
 * @brief Установка половины страницы в область $8000-$BFFF (режим расширенной адресации)
 * @param page_num Номер страницы (0-63)
 * @param half_page 0 - первая половина ($0000-$3FFF), 1 - вторая половина ($4000-$7FFF)
 */
void ZX_NEOGS_set_memory_page_extended_low(uint8_t page_num, uint8_t half_page);

/**
 * @brief Установка половины страницы в область $C000-$FFFF (режим расширенной адресации)
 * @param page_num Номер страницы (0-63)
 * @param half_page 0 - первая половина ($0000-$3FFF), 1 - вторая половина ($4000-$7FFF)
 */
void ZX_NEOGS_set_memory_page_extended_high(uint8_t page_num, uint8_t half_page);

/**
 * @brief Включение/выключение режима расширенной адресации страниц
 * @param enabled 1 - включить режим расширенной адресации, 0 - выключить
 */
void ZX_NEOGS_set_extended_paging(uint8_t enabled);

/**
 * @brief Переключение между ПЗУ и ОЗУ во всех областях адресного пространства
 * @param ram_enabled 1 - включить ОЗУ во всех областях, 0 - использовать ПЗУ в $0000-$3FFF и $8000-$FFFF
 */
void ZX_NEOGS_set_ram_everywhere(uint8_t ram_enabled);

/**
 * @brief Защита нулевой страницы ОЗУ от записи
 * @param protected 1 - защитить от записи, 0 - разрешить запись
 */
void ZX_NEOGS_set_zero_page_protection(uint8_t protected);

/**
 * @brief Установка 16К страницы в окно $0000-$3FFF
 * @param page_num Номер 16К страницы (0-255 для адресации 0-4МБ)
 */
void ZX_NEOGS_set_16k_page_0(uint8_t page_num);

/**
 * @brief Установка 16К страницы в окно $4000-$7FFF
 * @param page_num Номер 16К страницы (0-255 для адресации 0-4МБ)
 */
void ZX_NEOGS_set_16k_page_1(uint8_t page_num);

/**
 * @brief Установка 16К страницы в окно $8000-$BFFF
 * @param page_num Номер 16К страницы (0-255 для адресации 0-4МБ)
 */
void ZX_NEOGS_set_16k_page_2(uint8_t page_num);

/**
 * @brief Установка 16К страницы в окно $C000-$FFFF
 * @param page_num Номер 16К страницы (0-255 для адресации 0-4МБ)
 */
void ZX_NEOGS_set_16k_page_3(uint8_t page_num);

/**
 * @brief Установка громкости канала 1
 * @param volume Громкость (0-63, где 0 - выключено, 63 - максимум)
 */
void ZX_NEOGS_set_volume_1(uint8_t volume);

/**
 * @brief Установка громкости канала 2
 * @param volume Громкость (0-63, где 0 - выключено, 63 - максимум)
 */
void ZX_NEOGS_set_volume_2(uint8_t volume);

/**
 * @brief Установка громкости канала 3
 * @param volume Громкость (0-63, где 0 - выключено, 63 - максимум)
 */
void ZX_NEOGS_set_volume_3(uint8_t volume);

/**
 * @brief Установка громкости канала 4
 * @param volume Громкость (0-63, где 0 - выключено, 63 - максимум)
 */
void ZX_NEOGS_set_volume_4(uint8_t volume);

/**
 * @brief Установка громкости канала 5
 * @param volume Громкость (0-63, где 0 - выключено, 63 - максимум)
 */
void ZX_NEOGS_set_volume_5(uint8_t volume);

/**
 * @brief Установка громкости канала 6
 * @param volume Громкость (0-63, где 0 - выключено, 63 - максимум)
 */
void ZX_NEOGS_set_volume_6(uint8_t volume);

/**
 * @brief Установка громкости канала 7
 * @param volume Громкость (0-63, где 0 - выключено, 63 - максимум)
 */
void ZX_NEOGS_set_volume_7(uint8_t volume);

/**
 * @brief Установка громкости канала 8
 * @param volume Громкость (0-63, где 0 - выключено, 63 - максимум)
 */
void ZX_NEOGS_set_volume_8(uint8_t volume);

/**
 * @brief Установка режима звуковых каналов
 * @param mode Режим: 0 - 4 канала, 1 - 8 каналов, 2 - 4 канала с паннингом
 */
void ZX_NEOGS_set_sound_mode(uint8_t mode);

/**
 * @brief Установка громкости всех каналов (4-канальный режим)
 * @param volume1 Громкость канала 1 (0-63)
 * @param volume2 Громкость канала 2 (0-63)
 * @param volume3 Громкость канала 3 (0-63)
 * @param volume4 Громкость канала 4 (0-63)
 */
void ZX_NEOGS_set_volumes_4ch(uint8_t volume1, uint8_t volume2, uint8_t volume3, uint8_t volume4);

/**
 * @brief Установка громкости всех каналов (8-канальный режим)
 * @param volume1 Громкость канала 1 (0-63)
 * @param volume2 Громкость канала 2 (0-63)
 * @param volume3 Громкость канала 3 (0-63)
 * @param volume4 Громкость канала 4 (0-63)
 * @param volume5 Громкость канала 5 (0-63)
 * @param volume6 Громкость канала 6 (0-63)
 * @param volume7 Громкость канала 7 (0-63)
 * @param volume8 Громкость канала 8 (0-63)
 */
void ZX_NEOGS_set_volumes_8ch(uint8_t volume1, uint8_t volume2, uint8_t volume3, uint8_t volume4, uint8_t volume5, uint8_t volume6, uint8_t volume7, uint8_t volume8);

/**
 * @brief Установка громкости всех каналов (4-канальный режим с паннингом)
 * @param left_vol1 Громкость левого канала 1 (0-63)
 * @param left_vol2 Громкость левого канала 2 (0-63)
 * @param left_vol3 Громкость левого канала 3 (0-63)
 * @param left_vol4 Громкость левого канала 4 (0-63)
 * @param right_vol1 Громкость правого канала 1 (0-63)
 * @param right_vol2 Громкость правого канала 2 (0-63)
 * @param right_vol3 Громкость правого канала 3 (0-63)
 * @param right_vol4 Громкость правого канала 4 (0-63)
 */
void ZX_NEOGS_set_volumes_4ch_panning(uint8_t left_vol1, uint8_t left_vol2, uint8_t left_vol3, uint8_t left_vol4, uint8_t right_vol1, uint8_t right_vol2, uint8_t right_vol3,
                                      uint8_t right_vol4);

/**
 * @brief Выключение всех звуковых каналов
 */
void ZX_NEOGS_silence_all_channels(void);

/**
 * @brief Отправка байта в SD-карту
 * @param data Байт для отправки
 */
void ZX_NEOGS_sd_send_byte(uint8_t data);

/**
 * @brief Чтение байта из SD-карты
 * @return Принятый байт
 */
uint8_t ZX_NEOGS_sd_read_byte(void);

/**
 * @brief Чтение байта из SD-карты и отправка 0xFF
 * @return Принятый байт
 */
uint8_t ZX_NEOGS_sd_read_and_send_ff(void);

/**
 * @brief Установка сигнала CS для SD-карты
 * @param cs_state 0 - активировать CS (низкий уровень), 1 - деактивировать CS (высокий уровень)
 */
void ZX_NEOGS_sd_set_cs(uint8_t cs_state);

/**
 * @brief Отправка серии единичных байтов в SD-карту
 * @param count Количество байтов 0xFF для отправки
 */
void ZX_NEOGS_sd_send_ones(uint8_t count);

/**
 * @brief Отправка команды в SD-карту
 * @param cmd Массив из 6 байт команды (команда + аргумент + CRC)
 */
void ZX_NEOGS_sd_send_command(const uint8_t *cmd);

/**
 * @brief Ожидание ответа от SD-карты с таймаутом
 * @param expected_value Ожидаемое значение (обычно 0x00 для успеха)
 * @param timeout Максимальное количество попыток
 * @return 1 - получен ожидаемый ответ, 0 - таймаут
 */
uint8_t ZX_NEOGS_sd_wait_response(uint8_t expected_value, uint8_t timeout);

/**
 * @brief Ожидание отсутствия 0xFF в ответе (для команд типа CMD1)
 * @param timeout Максимальное количество попыток
 * @return 1 - получен ответ отличный от 0xFF, 0 - таймаут
 */
uint8_t ZX_NEOGS_sd_wait_not_ff(uint8_t timeout);

/**
 * @brief Чтение статуса SD-карты
 * @return Значение из порта SSTAT
 */
uint8_t ZX_NEOGS_sd_get_status(void);

/**
 * @brief Проверка наличия SD-карты
 * @return 1 - карта обнаружена, 0 - карта отсутствует
 * @warning Не рекомендуется использовать из-за возможных проблем с контактами
 */
bool ZX_NEOGS_sd_is_card_present(void);

/**
 * @brief Проверка флажка защиты от записи
 * @return 1 - защита включена, 0 - защита выключена
 * @warning Флажок не связан с реальной защитой от записи
 */
bool ZX_NEOGS_sd_is_write_protected(void);

/**
 * @brief Установка бита в порте SCTRL
 * @param bit_mask Маска бита для установки
 * @param set_to_one 1 - установить в 1, 0 - установить в 0
 */
void ZX_NEOGS_sctrl_set_bit(uint8_t bit_mask, bool set_to_one);

/**
 * @brief Одновременная установка нескольких битов в порте SCTRL
 * @param bit_mask Маска битов для изменения
 * @param set_to_one 1 - установить все биты в 1, 0 - установить все биты в 0
 */
void ZX_NEOGS_sctrl_set_bits(uint8_t bit_mask, bool set_to_one);

/**
 * @brief Чтение текущего состояния порта SCTRL
 * @return Текущее значение порта SCTRL
 */
uint8_t ZX_NEOGS_sctrl_read_state(void);

/**
 * @brief Установка сигнала сброса MP3-декодера
 * @param reset_active 1 - активировать сброс (низкий уровень), 0 - деактивировать сброс
 */
void ZX_NEOGS_mp3_set_reset(bool reset_active);

/**
 * @brief Установка сигнала CS для MP3-декодера
 * @param cs_active 1 - активировать CS (низкий уровень), 0 - деактивировать CS (высокий уровень)
 */
void ZX_NEOGS_mp3_set_cs(bool cs_active);

/**
 * @brief Установка частоты Fsck для управляющего интерфейса MP3-декодера
 * @param spd0 Значение бита SPD0
 * @param spd1 Значение бита SPD1
 */
void ZX_NEOGS_mp3_set_control_speed(bool spd0, bool spd1);

/**
 * @brief Установка частоты Fsck для интерфейса данных MP3-декодера
 * @param half_speed 1 - половинная скорость, 0 - полная скорость
 */
void ZX_NEOGS_mp3_set_data_speed(bool half_speed);

/**
 * @brief Отправка байта в управляющий интерфейс MP3-декодера
 * @param data Байт для отправки
 */
void ZX_NEOGS_mp3_send_control_byte(uint8_t data);

/**
 * @brief Чтение байта из управляющего интерфейса MP3-декодера
 * @return Принятый байт
 */
uint8_t ZX_NEOGS_mp3_read_control_byte(void);

/**
 * @brief Отправка байта в интерфейс данных MP3-декодера
 * @param data Байт для отправки
 */
void ZX_NEOGS_mp3_send_data_byte(uint8_t data);

/**
 * @brief Проверка готовности управляющего интерфейса MP3-декодера
 * @return 1 - интерфейс готов, 0 - интерфейс занят
 */
bool ZX_NEOGS_mp3_is_control_ready(void);

/**
 * @brief Проверка готовности интерфейса данных MP3-декодера
 * @return 1 - интерфейс готов к приёму данных, 0 - интерфейс занят
 */
bool ZX_NEOGS_mp3_is_data_ready(void);

/**
 * @brief Программная пауза для SPI-обмена на частоте Fcpu/2
 * @param ticks Количество тактов паузы (обычно 16 или 18)
 */
void ZX_NEOGS_spi_delay_cpu_div2(uint8_t ticks);

/**
 * @brief Ожидание готовности SPI-интерфейса (для низких частот)
 * @param timeout Максимальное количество попыток
 * @return 1 - интерфейс готов, 0 - таймаут
 */
bool ZX_NEOGS_spi_wait_ready(uint8_t timeout);

/**
 * @brief Полный цикл SPI-обмена: отправка байта и приём ответа с паузами
 * @param send_port Порт для отправки (например, ZX_NEOGS_INNER_PORT_SD_SEND)
 * @param read_port Порт для чтения (например, ZX_NEOGS_INNER_PORT_SD_READ)
 * @param data Байт для отправки
 * @return Принятый байт
 */
uint8_t ZX_NEOGS_spi_exchange(uint8_t send_port, uint8_t read_port, uint8_t data);

/**
 * @brief Быстрая пересылка байта из SD-карты в MP3-декодер
 * @return Принятый от SD-карты байт (также отправлен в MP3-декодер)
 */
uint8_t ZX_NEOGS_sd_to_mp3_fast_transfer(void);

/**
 * @brief Аппаратный сброс MP3-декодера
 */
void ZX_NEOGS_mp3_hardware_reset(void);

/**
 * @brief Отправка блока MP3-данных
 * @param buffer Указатель на буфер с данными
 * @param size Размер буфера
 * @return Количество отправленных байт
 */
uint16_t ZX_NEOGS_mp3_send_data_block(const uint8_t *buffer, uint16_t size);

/**
 * @brief Отправка 2048 байт нулей в конце MP3-файла
 */
void ZX_NEOGS_mp3_send_end_silence(void);

/**
 * @brief Выбор DMA модуля для работы
 * @param module Модуль: ZX_NEOGS_DMA_ZX, ZX_NEOGS_DMA_SD, ZX_NEOGS_DMA_MP3
 */
void ZX_NEOGS_dma_select_module(uint8_t module);

/**
 * @brief Установка 24-битного адреса для DMA
 * @param address Адрес в памяти NeoGS (0-1FFFFF для 2МБ)
 */
void ZX_NEOGS_dma_set_address(uint32_t address);

/**
 * @brief Чтение текущего адреса DMA
 * @return Текущий 24-битный адрес
 */
uint32_t ZX_NEOGS_dma_get_address(void);

/**
 * @brief Чтение состояния и управление DMA
 * @return Значение порта управления и состояния DMA
 */
uint8_t ZX_NEOGS_dma_get_control_state(void);

/**
 * @brief Включение DMA для обмена со спектрумом
 * @note После включения необходимо сделать паузу для gs105a
 */
void ZX_NEOGS_dma_enable(void);

/**
 * @brief Выключение DMA
 */
void ZX_NEOGS_dma_disable(void);

/**
 * @brief Запуск DMA-передачи (для ZX-модуля)
 * @param direction 0 - чтение из NeoGS в ZX, 1 - запись из ZX в NeoGS
 */
void ZX_NEOGS_dma_start_transfer(uint8_t direction);

/**
 * @brief Остановка DMA-передачи
 */
void ZX_NEOGS_dma_stop_transfer(void);

/**
 * @brief Проверка активности DMA-передачи
 * @return 1 - передача активна, 0 - передача остановлена
 */
bool ZX_NEOGS_dma_is_active(void);

/**
 * @brief Настройка DMA для обмена данными между ZX и NeoGS
 * @param neo_gs_address Адрес в памяти NeoGS
 * @param direction 0 - чтение из NeoGS, 1 - запись в NeoGS
 */
void ZX_NEOGS_dma_setup_zx_transfer(uint32_t neo_gs_address, uint8_t direction);

/**
 * @brief Копирование блока данных из ZX в NeoGS через DMA
 * @param zx_source Адрес источника в памяти ZX
 * @param neo_gs_dest Адрес назначения в NeoGS
 * @param size Размер блока
 * @note Использует запись в область $0000-$3FFF для передачи данных
 */
void ZX_NEOGS_dma_copy_from_zx(uint16_t zx_source, uint32_t neo_gs_dest, uint16_t size);

/**
 * @brief Копирование блока данных из NeoGS в ZX через DMA
 * @param neo_gs_source Адрес источника в NeoGS
 * @param zx_dest Адрес назначения в ZX
 * @param size Размер блока
 * @note Использует чтение из памяти $0000-$3FFF для приёма данных
 */
void ZX_NEOGS_dma_copy_to_zx(uint32_t neo_gs_source, uint16_t zx_dest, uint16_t size);

/**
 * @brief Вход в загрузчик NeoGS
 * @note Последовательность: сброс, ожидание, отправка байтов 0x55 и 0xAA
 */
void ZX_NEOGS_bootloader_enter(void);

/**
 * @brief Загрузка прошивки со стороны Spectrum (команда #00)
 * @param source_address Адрес источника прошивки в памяти Spectrum
 * @note Загружает 32Кб в страницу 0 по адресу 0, но не запускает
 */
void ZX_NEOGS_bootloader_load_firmware_from_spectrum(uint16_t source_address);

/**
 * @brief Запуск прошивки (команда #01)
 * @note Устанавливает защиту страницы 0, частоту 20 МГц
 */
void ZX_NEOGS_bootloader_run_firmware(void);

/**
 * @brief Загрузка и запуск прошивки из ПЗУ (команда #02)
 */
void ZX_NEOGS_bootloader_run_rom_firmware(void);

/**
 * @brief Загрузка и запуск прошивки с SD карты (команда #03)
 */
void ZX_NEOGS_bootloader_run_sd_firmware(void);

/**
 * @brief Загрузка кода со стороны Spectrum (команда #04)
 * @param page_number Номер страницы для загрузки
 * @param source_address Адрес источника в памяти Spectrum
 * @param block_size Размер блока (не более 32768 байт)
 * @note Загружает по адресу #8000 (32768)
 */
void ZX_NEOGS_bootloader_load_code_from_spectrum(uint8_t page_number, uint16_t source_address, uint16_t block_size);

/**
 * @brief Загрузка файла с SD карты (команда #05)
 * @param page_number Номер страницы для загрузки
 * @param file_path Указатель на строку с путём к файлу
 * @note Путь в формате DIR1/DIR2/FILENAME.EXT в верхнем регистре
 */
void ZX_NEOGS_bootloader_load_file_from_sd(uint8_t page_number, const char *file_path);

/**
 * @brief Запуск кода в указанной странице по адресу (команда #06)
 * @param page_number Номер страницы
 * @param start_address Адрес запуска
 */
void ZX_NEOGS_bootloader_run_code(uint8_t page_number, uint16_t start_address);

/**
 * @brief Получение статуса последней операции с файлом (команда #07)
 * @return Статус: 0=файл загружен, 0xAA=не найден, 0xDD=FAT не найден, 0xEE=SD ошибка
 */
uint8_t ZX_NEOGS_bootloader_get_file_status(void);

/**
 * @brief Получение версии страницы (команда #08)
 * @param page_number Номер страницы
 * @param buffer Буфер для приёма текстовой строки версии
 * @param buffer_size Размер буфера
 * @note Строка заканчивается нулевым байтом
 */
void ZX_NEOGS_bootloader_get_page_version(uint8_t page_number, char *buffer, uint16_t buffer_size);

/**
 * @brief Получение CRC16 или информации о блоках (команда #09)
 * @param request Байт запроса (бит 7=1 - количество блоков, иначе номер блока)
 * @param error_code Указатель для сохранения кода ошибки
 * @return Значение CRC16 или количество блоков
 * @note НЕ РЕКОМЕНДУЕТСЯ для обычного использования
 */
uint16_t ZX_NEOGS_bootloader_get_crc_info(uint8_t request, uint8_t *error_code);

/**
 * @brief Загрузка файла обновления (команда #0A)
 * @note Имя файла фиксированное: NGS_ROM.UPD в корне SD карты
 */
void ZX_NEOGS_bootloader_load_update_file(void);

/**
 * @brief Установка/получение частоты процессора (команда #0B)
 * @param frequency Номер частоты (0=10МГц, 1=12МГц, 2=20МГц, 3=24МГц) или 0x80 для получения
 * @return Текущая частота (только при запросе с битом 7)
 */
uint8_t ZX_NEOGS_bootloader_set_get_cpu_frequency(uint8_t frequency);

/**
 * @brief Проверка загрузчика (команда #1D)
 * @return 0x76 если активен загрузчик NeoGS
 */
uint8_t ZX_NEOGS_bootloader_check_bootloader(void);

/**
 * @brief Инициализация MP3-плеера (маскировка команды #1F)
 */
void ZX_NEOGS_mp3_player_init(void);

/**
 * @brief Перезапуск кода без HARD RESET MP3 (команда #00)
 */
void ZX_NEOGS_mp3_player_restart(void);

/**
 * @brief Запуск проигрывания текущего файла (команда #02)
 */
void ZX_NEOGS_mp3_player_play(void);

/**
 * @brief Пауза проигрывания (команда #03)
 */
void ZX_NEOGS_mp3_player_pause(void);

/**
 * @brief Остановка проигрывания (команда #04)
 */
void ZX_NEOGS_mp3_player_stop(void);

/**
 * @brief Переход на предыдущий трек (команда #01)
 */
void ZX_NEOGS_mp3_player_previous_track(void);

/**
 * @brief Переход на следующий трек (команда #05)
 */
void ZX_NEOGS_mp3_player_next_track(void);

/**
 * @brief Переключение Treble/Bass (команда #06)
 */
void ZX_NEOGS_mp3_player_toggle_treble_bass(void);

/**
 * @brief Переключение Virtual Surround (команда #07)
 */
void ZX_NEOGS_mp3_player_toggle_surround(void);

/**
 * @brief Увеличение громкости на 1 (команда #08)
 */
void ZX_NEOGS_mp3_player_volume_up(void);

/**
 * @brief Уменьшение громкости на 1 (команда #09)
 */
void ZX_NEOGS_mp3_player_volume_down(void);

/**
 * @brief Переключение громкости (вкл/выкл) (команда #0A)
 */
void ZX_NEOGS_mp3_player_toggle_mute(void);

/**
 * @brief Получение времени проигрывания в текстовом формате (команда #0B)
 * @param buffer Буфер для приёма 6 байт (ЧЧММСС)
 * @note Формат: часы(1 цифра), минуты(2), секунды(2)
 */
void ZX_NEOGS_mp3_player_get_time_text(char *buffer);

/**
 * @brief Получение текущего номера файла (команда #0D)
 * @return 16-битный номер файла
 */
uint16_t ZX_NEOGS_mp3_player_get_current_file(void);

/**
 * @brief Установка номера файла для проигрывания (команда #0E)
 * @param file_number Номер файла
 */
void ZX_NEOGS_mp3_player_set_file(uint16_t file_number);

/**
 * @brief Передача 512 байт в MP3-декодер (команда #14)
 * @param data Указатель на данные
 */
void ZX_NEOGS_mp3_player_send_512_bytes(const uint8_t *data);

/**
 * @brief Получение информации о файле (команда #11)
 * @param entry_number Номер описателя
 * @param buffer Буфер для приёма 33 байт
 */
void ZX_NEOGS_mp3_player_get_file_info(uint16_t entry_number, char *buffer);

/**
 * @brief Получение количества файлов по расширению (команда #13)
 * @return Количество найденных файлов
 */
uint16_t ZX_NEOGS_mp3_player_get_files_count(void);

/**
 * @brief Получение перекодированного количества файлов (команда #15)
 * @return 5 байт перекодированного числа
 */
void ZX_NEOGS_mp3_player_get_files_count_text(char *buffer);

/**
 * @brief Получение перекодированного номера текущего файла+1 (команда #16)
 * @return 5 байт перекодированного числа
 */
void ZX_NEOGS_mp3_player_get_next_file_text(char *buffer);

/**
 * @brief Переключение HARD/SOFT RESET MP3 (команда #17)
 * @param enable 1=HARD RESET, 0=SOFT RESET
 */
void ZX_NEOGS_mp3_player_set_reset_mode(uint8_t enable);

/**
 * @brief Получение состояния параметров и громкости (команда #0C)
 * @return 16-битное состояние параметров
 * @note Биты: 15-Treble/Bass, 14-Mute, 13-NewFile, 12-ResetMode, 11-ChipType, 10-VS1001/1011, 9-MOD, 8-Surround, 7-0=Volume
 */
uint16_t ZX_NEOGS_mp3_player_get_status(void);

/**
 * @brief Получение информации о файле (команда #12)
 * @param entry_number Номер описателя
 * @param buffer Буфер для приёма 32 байт
 */
void ZX_NEOGS_mp3_player_get_file_entry(uint16_t entry_number, char *buffer);

/**
 * @brief Получение типа FAT (команда #10)
 * @return Тип FAT или 0xFF если ошибка
 */
uint8_t ZX_NEOGS_mp3_player_get_fat_type(void);

/**
 * @brief Получение длинного имени файла (команда #11 с битом 7=1)
 * @param entry_number Номер описателя
 * @param buffer Буфер для приёма 256 байт
 */
void ZX_NEOGS_mp3_player_get_long_filename(uint16_t entry_number, char *buffer);

/**
 * @brief Управление темброблоком (команда #1A, только VS1011)
 * @param treble_freq Частота Treble (0-15)
 * @param treble_level Уровень Treble (-8 до +7)
 * @param bass_freq Частота Bass (2-15)
 * @param bass_level Уровень Bass (0-15)
 * @param change_treble 1=менять Treble, 0=не менять
 * @param change_bass_freq 1=менять частоту Bass, 0=не менять
 * @param change_treble_level 1=менять уровень Treble, 0=не менять
 * @param change_bass_level 1=менять уровень Bass, 0=не менять
 * @param treble_up 1=увеличить, 0=уменьшить (для уровня/частоты)
 */
void ZX_NEOGS_mp3_player_set_tone_control(uint8_t treble_freq, int8_t treble_level, uint8_t bass_freq, uint8_t bass_level, uint8_t change_treble, uint8_t change_bass_freq,
                                          uint8_t change_treble_level, uint8_t change_bass_level, uint8_t treble_up);

/**
 * @brief Получение положения регуляторов тембра (команда #1B)
 * @param buffer Буфер для приёма 8 байт
 * @note Формат: 12-частота TREBLE, 34-уровень TREBLE, 56-частота BASS, 78-уровень BASS
 */
void ZX_NEOGS_mp3_player_get_tone_position(char *buffer);

/**
 * @brief Получение информации о текущем файле (команда #1C)
 * @return 16-битная информация о файле
 * @note Биты: 15-12=режим, 11-8=битрейт, 7-6=стерео/моно, 5-4=слой, 3-2=частота, 1-0=MPEG
 */
uint16_t ZX_NEOGS_mp3_player_get_current_file_info(void);

/**
 * @brief Переход в предыдущую директорию (команда #18)
 */
void ZX_NEOGS_mp3_player_previous_directory(void);

/**
 * @brief Переход в следующую директорию (команда #19)
 */
void ZX_NEOGS_mp3_player_next_directory(void);

/**
 * @brief Переключение режима сброса MP3 (команда #0F)
 */
void ZX_NEOGS_mp3_player_toggle_reset_mode(void);

/**
 * @brief Проверка что в GS стоит плеер (команда #1D с параметром 0)
 * @return 0x77 если плеер, иначе другие значения
 */
uint8_t ZX_NEOGS_mp3_player_check(void);

#endif
