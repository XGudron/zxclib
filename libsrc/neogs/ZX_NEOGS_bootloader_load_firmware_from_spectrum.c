#include "zx_neogs.h"

void ZX_NEOGS_bootloader_load_firmware_from_spectrum(uint16_t source_address) {
	zx_gs_command_register = ZX_NEOGS_BOOTLOADER_CMD_LOAD_FIRMWARE_FROM_SPECTRUM;
	ZX_GS_wait_command_ready();

	uint8_t *src = (uint8_t *)source_address;
	for (uint16_t i = 0; i < 0x8000; i++) {
		zx_gs_data_register = src[i];
		ZX_GS_wait_data_ready();
	}
}
