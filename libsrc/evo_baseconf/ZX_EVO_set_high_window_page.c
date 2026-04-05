#include "zx_evo_baseconf.h"

void ZX_EVO_set_high_window_page(uint8_t page) {
	ZX_EVO_toggle_shadow_ports(true);
	zx_evo_F7F7_shadow_port = ~page;
	ZX_EVO_toggle_shadow_ports(false);
}
