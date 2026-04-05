#include "zx_evo_baseconf.h"

void ZX_EVO_block_7FFD_port(void) { zx_evo_7FFD_port = ((ZX_EVO_lastvalue_port_7FFD & ~(1 << 5)) | (1 << 5)); }
