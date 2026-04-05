#include "zx_neogs.h"

void ZX_NEOGS_set_volumes_8ch(uint8_t volume1, uint8_t volume2, uint8_t volume3, uint8_t volume4, uint8_t volume5, uint8_t volume6, uint8_t volume7, uint8_t volume8) {
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_1, volume1 & 0x3F);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_2, volume2 & 0x3F);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_3, volume3 & 0x3F);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_4, volume4 & 0x3F);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_5, volume5 & 0x3F);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_6, volume6 & 0x3F);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_7, volume7 & 0x3F);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_8, volume8 & 0x3F);
}
