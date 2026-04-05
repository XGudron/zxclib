#include "zx_gs.h"

uint8_t ZX_GS_peek_from_de_addr(void) {
	zx_gs_command_register = ZX_GS_CMD_PEEK_FROM_DE_ADDR;
	ZX_GS_wait_command_ready();
	ZX_GS_wait_data_available();
	return zx_gs_output_register;
}
