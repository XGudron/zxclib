#include "zx_neogs.h"

void ZX_NEOGS_set_ram_everywhere(uint8_t ram_enabled) {
	uint8_t value = ZX_GS_in_from_any_port(ZX_NEOGS_INNER_PORT_CONFIG0);
	if (ram_enabled) {
		value |= ZX_NEOGS_CONFIG_NO_ROM_MASK;
	} else {
		value &= ~ZX_NEOGS_CONFIG_NO_ROM_MASK;
	}
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_CONFIG0, value);
}
