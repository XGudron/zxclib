#include "zx_evo_baseconf.h"

void ZX_EVO_set_cpu_speed(zx_evo_cpu_speed_t cpu_speed) {
	switch (cpu_speed) {
	case ZX_EVO_CPU_3_5MHZ:
		ZX_EVO_write_port_xx77(ZX_EVO_lastvalue_port_xx77 & ~(1 << 3));
		zx_evo_EFF7_noshadow_port = (ZX_EVO_lastvalue_port_EFF7 | (1 << 4));
		break;
	case ZX_EVO_CPU_7MHZ:
		ZX_EVO_write_port_xx77(ZX_EVO_lastvalue_port_xx77 & ~(1 << 3));
		zx_evo_EFF7_noshadow_port = (ZX_EVO_lastvalue_port_EFF7 & ~(1 << 4));
		break;
	case ZX_EVO_CPU_14MHZ:
		ZX_EVO_write_port_xx77(ZX_EVO_lastvalue_port_xx77 | (1 << 3));
		break;
	}
}
