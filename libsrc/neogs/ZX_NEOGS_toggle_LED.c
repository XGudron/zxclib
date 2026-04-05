#include "zx_neogs.h"

void ZX_NEOGS_toggle_LED(void) { zx_neogs_control_register = ZX_NEOGS_CONTROL_CMD_LED; }
