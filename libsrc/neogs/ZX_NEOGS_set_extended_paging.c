#include "zx_neogs.h"

void ZX_NEOGS_set_extended_paging(uint8_t enabled) {
	uint8_t value = ZX_GS_in_from_any_port(ZX_NEOGS_INNER_PORT_CONFIG0);
	if (enabled) {
		value |= ZX_NEOGS_CONFIG_ENTENDED_PAGING_MASK;
	} else {
		value &= ~ZX_NEOGS_CONFIG_ENTENDED_PAGING_MASK;
	}
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_CONFIG0, value);
}
