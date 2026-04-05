#include "zx_evo_baseconf.h"

void ZX_EVO_toggle_trdos_and_shadow_hold(bool enable) {
	if (enable) {
		ZX_EVO_write_port_xx77(ZX_EVO_lastvalue_port_xx77 & ~(1 << 6));
	} else {
		ZX_EVO_write_port_xx77(ZX_EVO_lastvalue_port_xx77 | (1 << 6));
	}
}
