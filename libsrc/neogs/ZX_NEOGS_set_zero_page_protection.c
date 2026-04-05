#include "zx_neogs.h"

void ZX_NEOGS_set_zero_page_protection(uint8_t protected) {
	uint8_t value = ZX_GS_in_from_any_port(ZX_NEOGS_INNER_PORT_CONFIG0);
	if (protected) {
		value |= ZX_NEOGS_CONFIG_ROM_RO_MASK;
	} else {
		value &= ~ZX_NEOGS_CONFIG_ROM_RO_MASK;
	}
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_CONFIG0, value);
}
