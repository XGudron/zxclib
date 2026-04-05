#include "zx_neogs.h"

void ZX_NEOGS_reset(void) { zx_neogs_control_register = ZX_NEOGS_CONTROL_CMD_RESET; }
