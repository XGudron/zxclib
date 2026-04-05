#include "zx_gs.h"

uint8_t ZX_GS_peek_from_addr(uint16_t addr) {
	zx_gs_data_register = addr & 0xFF;
	zx_gs_command_register = ZX_GS_CMD_PEEK_FROM_ADDR;
	ZX_GS_wait_command_ready();
	zx_gs_data_register = (addr >> 8) & 0xFF;
	ZX_GS_wait_data_available();
	return zx_gs_output_register;
}
