#include "zx_neogs.h"

void ZX_NEOGS_sd_send_ones(uint8_t count) {
	while (count--) {
		ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_SD_SEND, 0xFF);
	}
}
