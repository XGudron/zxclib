#include "zx_neogs.h"

uint16_t ZX_NEOGS_bootloader_get_crc_info(uint8_t request, uint8_t *error_code) {
	zx_gs_data_register = request;
	zx_gs_command_register = ZX_NEOGS_BOOTLOADER_CMD_GET_CRC_INFO;
	ZX_GS_wait_command_ready();

	// Чтение ответа
	*error_code = zx_gs_data_register;
	ZX_GS_wait_data_available();
	uint8_t low_byte = zx_gs_data_register;
	ZX_GS_wait_data_available();
	uint8_t high_byte = zx_gs_data_register;

	return (uint16_t)high_byte << 8 | low_byte;
}
