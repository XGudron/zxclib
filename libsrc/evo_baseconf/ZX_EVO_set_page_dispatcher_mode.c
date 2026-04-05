#include "zx_evo_baseconf.h"

void ZX_EVO_set_page_dispatcher_mode(uint8_t window, uint8_t page, bool ramnrom, bool dos7ffd) {
	ZX_EVO_toggle_shadow_ports(true);
	uint8_t value = ((~page) & 0x3F) | (ramnrom << 6) | (dos7ffd << 7);

	switch (window) {
	case 0:
		zx_evo_3FF7_shadow_port = value;
		break;
	case 1:
		zx_evo_7FF7_shadow_port = value;
		break;
	case 2:
		zx_evo_BFF7_shadow_port = value;
		break;
	case 3:
		zx_evo_FFF7_shadow_port = value;
		break;
	}
	ZX_EVO_toggle_shadow_ports(false);
}
