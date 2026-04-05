#include "zx_evo_baseconf.h"

void ZX_EVO_beeper_write(bool status) { zx_evo_xxFE_port = (zx_evo_0FBD_port_last_border_value & 0x7) | ((status & 0x01) << 4); }
