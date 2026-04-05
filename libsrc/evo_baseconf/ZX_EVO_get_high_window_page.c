#include "zx_evo_baseconf.h"

uint8_t ZX_EVO_get_high_window_page(void) {
	uint8_t memory_map = (ZX_EVO_lastvalue_port_7FFD >> 4) & 0x01;
	if (memory_map) {
		return ~zx_evo_07BD_port;
	} else {
		return ~zx_evo_03BD_port;
	}
}