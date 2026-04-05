#include "zx_evo_baseconf.h"

void ZX_EVO_select_mode(zx_evo_mode_t mode) { zx_evo_EFF7_noshadow_port = ((ZX_EVO_lastvalue_port_EFF7 & ~(1 << 2)) | (mode << 2)); }
