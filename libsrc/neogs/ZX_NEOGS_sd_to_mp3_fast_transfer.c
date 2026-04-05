#include "zx_neogs.h"

uint8_t ZX_NEOGS_sd_to_mp3_fast_transfer(void) {
	uint8_t data = ZX_GS_in_from_any_port(ZX_NEOGS_INNER_PORT_SD_READ_N_START);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_MD_SEND, data);
	return data;
}
