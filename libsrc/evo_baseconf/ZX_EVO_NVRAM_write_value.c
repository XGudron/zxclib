#include "zx_evo_baseconf.h"

void ZX_EVO_NVRAM_write_value(uint8_t value) { zx_evo_BFF7_noshadow_port = value; }
