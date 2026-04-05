/**
 * @file zx_netusb.h
 * @brief Библиотека функций для работы с ZXNetUSB
 *
 * Данная библиотека предоставляет функции ZXNetUSB, описанные в руководстве программист
 *
 * Часть функций библиотеки требует доработки и отладки
 *
 * Автор: Dmitry Panin UA3REO
 * Компилятор: SDCC
 * Целевая платформа: ZX Spectrum
 */

#ifndef ZX_NETUSB_H
#define ZX_NETUSB_H

#include <stdint.h>

// ZXNETUSB Ports
#define ZX_NETUSB_IRQ_N_RESET_PORT 0x83AB // порт управления прерываниями и сбросом
#define ZX_NETUSB_CONTROL_PORT 0x82AB // порт управления SL811HS и W5300
#define ZX_NETUSB_NET_IO_MAPPING_PORT 0x81AB // порт IO-маппинга W5300
#define ZX_NETUSB_USB_ADDR_REGISTER_PORT 0x80AB // адресный регистр SL811HS
#define ZX_NETUSB_USB_DATA_REGISTER_PORT 0xAB // #00AB..#7FAB регистр данных SL811HS
#define ZX_NETUSB_NET_ADDR_SPACE_PORT 0xAB // #40AB..#7FAB – адресное пространство W5300

// Port definitions
static __sfr __banked __at ZX_NETUSB_IRQ_N_RESET_PORT zx_netusb_irq_n_reset_register;
static __sfr __banked __at ZX_NETUSB_CONTROL_PORT zx_netusb_control_register;
static __sfr __banked __at ZX_NETUSB_NET_IO_MAPPING_PORT zx_netusb_net_io_mapping_register;
static __sfr __banked __at ZX_NETUSB_USB_ADDR_REGISTER_PORT zx_netusb_usb_addr_register_register;

/**
 * @brief Состояние внутреннего сигнала прерывания (1 – есть сигнал). Всегда 0, если биты этого регистра 1 и 0 в нуле
 */
bool ZX_NETUSB_get_irq_state(void);

/**
 * @brief Если 1, то внутренний сигнал формирует /INT на ZX-Bus.
 */
void ZX_NETUSB_toggle_zxbus_int(bool enabled);

/**
 * @brief Если 0, то установлен сигнал сброса на SL811HS (nRST=0)
 */
void ZX_NETUSB_usb_toggle_reset(bool enabled);

/**
 * @brief Если 0, то установлен сигнал сброса на W5300 (/RESET=0)
 */
void ZX_NETUSB_net_toggle_reset(bool enabled);

/**
 * @brief Если 1, то сигнал INTRQ от SL811HS участвует в формировании внутреннего сигнала прерывания.
 */
void ZX_NETUSB_usb_toggle_intrq(bool enabled);

/**
 * @brief Если 1, то сигнал /INT от W5300 участвует в формировании внутреннего сигнала прерывания.
 */
void ZX_NETUSB_net_toggle_int(bool enabled);

/**
 * @brief Если 1, то установлен сигнал INTRQ от SL811HS (INTRQ=1)
 */
bool ZX_NETUSB_usb_get_intrq(void);

/**
 * @brief Если 1, то установлен сигнал /INT от W5300 (/INT=0)
 */
bool ZX_NETUSB_net_get_int(void);

/**
 * @brief Если 1, то на разъёме mini-USB присутствует питание (он подключен к хосту)
 */
bool ZX_NETUSB_usb_get_powered(void);

/**
 * @brief Управление сигналом M/S SL811HS. Если 0, то M/S=0 (SL811HS – хост).
 * Если 1, то M/S=1 (SL811HS – девайс). Изменение роли SL811HS
 * допускается только при нахождении её в ресете. Узнать о подключении
 * хоста к mini-USB можно опросом бита 7 данного порта.
 */
void ZX_NETUSB_usb_toggle_master_slave(bool master);

/**
 * @brief Если 1, то W5300 доступна в портах #00AB..#7FAB, при этом SL811HS в
 * этих же портах становится недоступна. Биты адреса W5300 ADDR[6:0]
 * равны битам ША A[14:8], также учитывается бит 3 данного порта.
 */
void ZX_NETUSB_net_toggle_port_adressing(bool enabled);

/**
 * @brief Если 1, то при любом обращении к W5300 инвертируется ADDR[0]
 * (действует как для mem-mapped обращений, так и для IO-mapped обращений).
 */
void ZX_NETUSB_net_toggle_invert_addr0(bool enabled);

/**
 * @brief Если 1, то адресное пространство W5300 подставляется вместо адресного
 * пространства ROM Z80 (см. также биты 1:0 данного порта).
 */
void ZX_NETUSB_net_toggle_rom_adressing(bool enabled);

/**
 * @brief Область адресного пространства Z80, в котором происходит подстановка 
 * адресного пространства W5300 вместо ROM. 2'b00 – #0000..#3FFF, 2'b01
 * – #4000..#7FFF, 2'b10 – #8000..#BFFF, 2'b11 – #C000..#FFFF.
 */
void ZX_NETUSB_net_set_rom_adressing_window(uint8_t window);

/**
 * @brief Старшие 4 бита адреса для W5300 (ADDR[9:6]) при обращении к ней через порты #40AB..#7FAB.
 */
void ZX_NETUSB_net_set_set_port_mapping_addr(uint8_t addr);

#endif
