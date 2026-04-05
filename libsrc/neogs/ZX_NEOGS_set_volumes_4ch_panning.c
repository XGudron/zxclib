#include "zx_neogs.h"

void ZX_NEOGS_set_volumes_4ch_panning(uint8_t left_vol1, uint8_t left_vol2, uint8_t left_vol3, uint8_t left_vol4, uint8_t right_vol1, uint8_t right_vol2, uint8_t right_vol3,
                                      uint8_t right_vol4) {
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_1, left_vol1 & 0x3F);  // Левый канал 1
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_2, left_vol2 & 0x3F);  // Левый канал 2
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_3, right_vol1 & 0x3F); // Правый канал 1
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_4, right_vol2 & 0x3F); // Правый канал 2
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_5, left_vol3 & 0x3F);  // Левый канал 3
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_6, left_vol4 & 0x3F);  // Левый канал 4
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_7, right_vol3 & 0x3F); // Правый канал 3
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_8, right_vol4 & 0x3F); // Правый канал 4
}
