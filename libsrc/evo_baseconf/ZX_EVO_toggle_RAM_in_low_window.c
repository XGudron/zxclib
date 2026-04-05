#include "zx_evo_baseconf.h"

void ZX_EVO_toggle_RAM_in_low_window(bool enable) { zx_evo_EFF7_noshadow_port = ((ZX_EVO_lastvalue_port_EFF7 & ~(1 << 3)) | (enable << 3)); }
