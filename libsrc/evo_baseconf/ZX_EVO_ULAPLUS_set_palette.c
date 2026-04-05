#include "zx_evo_baseconf.h"

void ZX_EVO_ULAPLUS_set_palette(uint8_t palette_idx, uint8_t palette_value) {
	zx_evo_BF3B_port = palette_idx;
	zx_evo_FF3B_port = palette_value;
}
