#include "zx_evo_baseconf.h"

void ZX_EVO_write_port_xx77(uint8_t value) {
	ZX_EVO_toggle_shadow_ports(true);
	uint8_t high_value = value >> 5;
	uint8_t low_value = value & 0xF;
	switch (high_value) {
	case 0:
		zx_evo_BC77_shadow_port = low_value;
		break;
	case 1:
		zx_evo_BD77_shadow_port = low_value;
		break;
	case 2:
		zx_evo_BE77_shadow_port = low_value;
		break;
	case 3:
		zx_evo_BF77_shadow_port = low_value;
		break;
	case 4:
		zx_evo_FC77_shadow_port = low_value;
		break;
	case 5:
		zx_evo_FD77_shadow_port = low_value;
		break;
	case 6:
		zx_evo_FE77_shadow_port = low_value;
		break;
	default:
		zx_evo_FF77_shadow_port = low_value;
		break;
	}
	ZX_EVO_toggle_shadow_ports(false);
}
