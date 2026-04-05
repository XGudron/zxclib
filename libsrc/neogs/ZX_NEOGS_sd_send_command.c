#include "zx_neogs.h"

void ZX_NEOGS_sd_send_command(const uint8_t *cmd) {
	for (uint8_t i = 0; i < 6; i++) {
		ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_SD_SEND, cmd[i]);
	}
}
