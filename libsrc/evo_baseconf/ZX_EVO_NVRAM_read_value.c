#include "zx_evo_baseconf.h"

uint8_t ZX_EVO_NVRAM_read_value(void) { return zx_evo_BFF7_noshadow_port; }
