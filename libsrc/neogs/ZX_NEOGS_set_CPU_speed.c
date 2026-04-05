#include "zx_neogs.h"

void ZX_NEOGS_set_CPU_speed(uint8_t mask) {
	uint8_t value = ZX_GS_in_from_any_port(ZX_NEOGS_INNER_PORT_CONFIG0);
	value = (value & ~ZX_NEOGS_CONFIG_CPU_SPEED_MASK) | (mask & ZX_NEOGS_CONFIG_CPU_SPEED_MASK);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_CONFIG0, value);
}
