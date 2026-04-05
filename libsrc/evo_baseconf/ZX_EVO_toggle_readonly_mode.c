#include "zx_evo_baseconf.h"

void ZX_EVO_toggle_readonly_mode(uint8_t window, bool enable) {
	ZX_EVO_toggle_shadow_ports(true);
	switch (window) {
	case 0:
		if (enable) {
			zx_evo_3BF7_shadow_port = 0x01;
		} else {
			zx_evo_3BF7_shadow_port = 0x00;
		}
		break;
	case 1:
		if (enable) {
			zx_evo_7BF7_shadow_port = 0x01;
		} else {
			zx_evo_7BF7_shadow_port = 0x00;
		}
		break;
	case 2:
		if (enable) {
			zx_evo_BBF7_shadow_port = 0x01;
		} else {
			zx_evo_BBF7_shadow_port = 0x00;
		}
		break;
	case 3:
		if (enable) {
			zx_evo_FBF7_shadow_port = 0x01;
		} else {
			zx_evo_FBF7_shadow_port = 0x00;
		}
		break;
	}
	ZX_EVO_toggle_shadow_ports(false);
}
