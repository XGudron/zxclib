#include "zx_gs.h"

void ZX_GS_poke_to_20xx_addr(uint8_t addr_l, uint8_t byte) {
	zx_gs_data_register = addr_l;
	zx_gs_command_register = ZX_GS_CMD_POKE_TO_20XX_ADDR;
	ZX_GS_wait_command_ready();
	zx_gs_data_register = byte;
	ZX_GS_wait_data_ready();
}
