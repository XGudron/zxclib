#include "zx_neogs.h"

void ZX_NEOGS_mp3_send_data_byte(uint8_t data) { ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_MD_SEND, data); }
