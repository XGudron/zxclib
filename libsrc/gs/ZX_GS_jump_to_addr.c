#include "zx_gs.h"

void ZX_GS_jump_to_addr(uint16_t addr) {
	zx_gs_data_register = addr & 0xFF;
	zx_gs_command_register = ZX_GS_CMD_JUMP_TO_ADDR;
	ZX_GS_wait_command_ready();
	zx_gs_data_register = (addr >> 8) & 0xFF;
	ZX_GS_wait_data_ready();
}
