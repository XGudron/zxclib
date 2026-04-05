#include "zx_evo_baseconf.h"

void ZX_EVO_toggle_shadow_ports(bool enable) {
	if (enable) {
		zx_evo_xxBF_port |= 0x01;
	} else {
		zx_evo_xxBF_port &= ~(0x01);
	}
}
