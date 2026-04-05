#include "zx_neogs.h"

void ZX_NEOGS_bootloader_enter(void) {
	// Сброс NeoGS
	zx_gs_command_register = 0x80;
	__asm__("nop");
	__asm__("nop");
	__asm__("nop");

	// Отправка первого ожидаемого байта
	zx_gs_data_register = 0x55;
	zx_gs_command_register = 0x55;
	ZX_GS_wait_command_ready();

	// Отправка второго ожидаемого байта
	zx_gs_data_register = 0xAA;
	zx_gs_command_register = 0xAA;
	ZX_GS_wait_command_ready();
}
