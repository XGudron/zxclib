#include "zx_evo_baseconf.h"

void ZX_EVO_toggle_memory_dispatcher(bool enable) {
	if (enable) {
		ZX_EVO_write_port_xx77(ZX_EVO_lastvalue_port_xx77 | (1 << 5));
	} else {
		ZX_EVO_write_port_xx77(ZX_EVO_lastvalue_port_xx77 & ~(1 << 5));
	}
}
