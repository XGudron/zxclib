#include "zx_evo_baseconf.h"

void ZX_EVO_tape_write(bool status) { zx_evo_xxFE_port = status << 3; }
