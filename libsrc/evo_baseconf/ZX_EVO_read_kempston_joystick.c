#include "zx_evo_baseconf.h"

uint8_t ZX_EVO_read_kempston_joystick(void) { return zx_evo_xx1F_noshadow_port; }
