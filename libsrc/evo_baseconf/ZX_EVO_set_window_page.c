#include "zx_evo_baseconf.h"

void ZX_EVO_set_window_page(uint8_t window, uint8_t page) {
	ZX_EVO_toggle_shadow_ports(true);
	switch (window) {
	case 0:
		zx_evo_37F7_shadow_port = ~page;
		break;
	case 1:
		zx_evo_77F7_shadow_port = ~page;
		break;
	case 2:
		zx_evo_B7F7_shadow_port = ~page;
		break;
	case 3:
		zx_evo_F7F7_shadow_port = ~page;
		break;
	}
	ZX_EVO_toggle_shadow_ports(false);
}
