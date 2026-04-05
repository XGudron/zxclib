#include "zx_gs.h"

void ZX_GS_poke_to_addr(uint8_t byte, uint16_t addr) {
	zx_gs_data_register = byte;
	zx_gs_command_register = ZX_GS_CMD_POKE_TO_ADDR;
	ZX_GS_wait_command_ready();
	zx_gs_data_register = addr & 0xFF;
	ZX_GS_wait_data_ready();
	zx_gs_data_register = (addr >> 8) & 0xFF;
	ZX_GS_wait_data_ready();
}
