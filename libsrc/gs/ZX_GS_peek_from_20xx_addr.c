#include "zx_gs.h"

uint8_t ZX_GS_peek_from_20xx_addr(uint8_t addr_l) {
	zx_gs_data_register = addr_l;
	zx_gs_command_register = ZX_GS_CMD_PEEK_FROM_20XX_ADDR;
	ZX_GS_wait_command_ready();
	ZX_GS_wait_data_available();
	return zx_gs_output_register;
}
