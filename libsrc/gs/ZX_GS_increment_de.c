#include "zx_gs.h"

void ZX_GS_increment_de(void) {
	zx_gs_command_register = ZX_GS_CMD_INCREMENT_DE;
	ZX_GS_wait_command_ready();
}
