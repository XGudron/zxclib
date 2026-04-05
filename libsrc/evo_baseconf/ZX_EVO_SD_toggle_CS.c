#include "zx_evo_baseconf.h"

void ZX_EVO_SD_toggle_CS(bool status) { zx_evo_xx77_noshadow_port = status << 1; }
