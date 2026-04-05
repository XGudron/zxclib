#include "zx_neogs.h"

uint8_t ZX_NEOGS_sctrl_read_state(void) { return ZX_GS_in_from_any_port(ZX_NEOGS_INNER_PORT_SERIAL_CONTROL); }
