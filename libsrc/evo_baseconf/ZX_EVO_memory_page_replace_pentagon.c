#include "zx_evo_baseconf.h"

void ZX_EVO_memory_page_replace_pentagon(uint8_t mask) { zx_evo_7FFD_port = ((ZX_EVO_lastvalue_port_7FFD & 0x18) | (mask & 0x7) | ((mask & 0x38) << 2)); }
