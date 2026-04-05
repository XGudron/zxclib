#include "zx_evo_baseconf.h"

void ZX_EVO_SD_write_byte(uint8_t data) { zx_evo_xx57_noshadow_port = data; }
