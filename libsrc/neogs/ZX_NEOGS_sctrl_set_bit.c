#include "zx_neogs.h"

void ZX_NEOGS_sctrl_set_bit(uint8_t bit_mask, bool set_to_one) {
	uint8_t value;
	if (set_to_one) {
		value = ZX_NEOGS_SET_N_CLR_MASK | bit_mask;
	} else {
		value = bit_mask;
	}
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_SERIAL_CONTROL, value);
}
