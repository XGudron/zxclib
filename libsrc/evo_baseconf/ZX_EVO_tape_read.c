#include "zx_evo_baseconf.h"

bool ZX_EVO_tape_read(void) { return (zx_evo_xxFE_port >> 6) & 0x01; }
