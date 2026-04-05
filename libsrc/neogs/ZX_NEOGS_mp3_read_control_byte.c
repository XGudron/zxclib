#include "zx_neogs.h"

uint8_t ZX_NEOGS_mp3_read_control_byte(void) { return ZX_GS_in_from_any_port(ZX_NEOGS_INNER_PORT_MC_READ); }
