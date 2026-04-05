#include "zx_evo_baseconf.h"

void ZX_EVO_toggle_extended_palette(bool enable) {
	if (enable) {
		zx_evo_xxBF_port |= 0x20;
	} else {
		zx_evo_xxBF_port &= ~(0x20);
	}
}
