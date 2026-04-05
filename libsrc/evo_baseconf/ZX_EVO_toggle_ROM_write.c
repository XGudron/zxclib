#include "zx_evo_baseconf.h"

void ZX_EVO_toggle_ROM_write(bool enable) {
	if (enable) {
		zx_evo_xxBF_port |= 0x02;
	} else {
		zx_evo_xxBF_port &= ~(0x02);
	}
}
