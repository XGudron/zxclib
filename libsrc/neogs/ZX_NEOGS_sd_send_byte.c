#include "zx_neogs.h"

void ZX_NEOGS_sd_send_byte(uint8_t data) { ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_SD_SEND, data); }
