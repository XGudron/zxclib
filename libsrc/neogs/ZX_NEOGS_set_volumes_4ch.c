#include "zx_neogs.h"

void ZX_NEOGS_set_volumes_4ch(uint8_t volume1, uint8_t volume2, uint8_t volume3, uint8_t volume4) {
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_1, volume1 & 0x3F);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_2, volume2 & 0x3F);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_3, volume3 & 0x3F);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_4, volume4 & 0x3F);
}
