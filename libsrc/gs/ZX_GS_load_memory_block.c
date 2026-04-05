#include "zx_gs.h"

void ZX_GS_load_memory_block(uint16_t addr, uint8_t *data, uint16_t len) {
	uint16_t remaining = len;
	uint8_t *ptr = data;

	// Send length
	zx_gs_data_register = len & 0xFF;
	zx_gs_command_register = ZX_GS_CMD_LOAD_MEMORY_BLOCK;
	ZX_GS_wait_command_ready();
	zx_gs_data_register = (len >> 8) & 0xFF;
	ZX_GS_wait_data_ready();

	// Send address
	zx_gs_data_register = addr & 0xFF;
	ZX_GS_wait_data_ready();
	zx_gs_data_register = (addr >> 8) & 0xFF;
	ZX_GS_wait_data_ready();

	// Send data block
	while (remaining > 0) {
		zx_gs_data_register = *ptr;
		ZX_GS_wait_data_ready();
		remaining--;
		ptr++;
	}
}
