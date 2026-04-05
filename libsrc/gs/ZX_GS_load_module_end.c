#include "zx_gs.h"

void ZX_GS_load_module_end(void) {
	zx_gs_command_register = ZX_GS_CMD_CLOSE_STREAM;
	ZX_GS_wait_command_ready();
}
