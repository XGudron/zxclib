#include "zx_gs.h"

void ZX_GS_poke_to_de_addr(uint8_t byte) {
	zx_gs_data_register = byte;
	zx_gs_command_register = ZX_GS_CMD_POKE_TO_DE_ADDR;
	ZX_GS_wait_command_ready();
}
