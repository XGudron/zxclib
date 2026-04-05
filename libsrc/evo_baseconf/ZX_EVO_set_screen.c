#include "zx_evo_baseconf.h"

void ZX_EVO_set_screen(bool screen) { zx_evo_7FFD_port = ((ZX_EVO_lastvalue_port_7FFD & ~(1 << 3)) | (screen << 3)); }
