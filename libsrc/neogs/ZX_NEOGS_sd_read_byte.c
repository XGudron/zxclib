#include "zx_neogs.h"

uint8_t ZX_NEOGS_sd_read_byte(void) { return ZX_GS_in_from_any_port(ZX_NEOGS_INNER_PORT_SD_READ); }
