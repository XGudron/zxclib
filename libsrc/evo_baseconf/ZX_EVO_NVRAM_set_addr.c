#include "zx_evo_baseconf.h"

void ZX_EVO_NVRAM_set_addr(uint8_t addr) { zx_evo_DFF7_noshadow_port = addr; }
