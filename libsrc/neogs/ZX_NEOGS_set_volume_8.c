#include "zx_neogs.h"

void ZX_NEOGS_set_volume_8(uint8_t volume) { ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_8, volume & 0x3F); }
