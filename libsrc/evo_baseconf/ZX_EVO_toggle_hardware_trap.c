#include "zx_evo_baseconf.h"

void ZX_EVO_toggle_hardware_trap(bool enable) {
	if (enable) {
		zx_evo_xxBF_port |= 0x10;
	} else {
		zx_evo_xxBF_port &= ~(0x10);
	}
}
