#include "zx_evo_baseconf.h"

void ZX_EVO_ULAPLUS_toggle(bool enabled) {
	zx_evo_BF3B_port = 0x40;
	if (enabled) {
		zx_evo_FF3B_port = 0x01;
	} else {
		zx_evo_FF3B_port = 0x00;
	}
}
