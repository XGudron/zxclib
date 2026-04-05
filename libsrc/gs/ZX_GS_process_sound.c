#include "zx_gs.h"

void ZX_GS_process_sound(void) {
	zx_gs_command_register = ZX_GS_CMD_PROCESS_SOUND;
	ZX_GS_wait_command_ready();
}
