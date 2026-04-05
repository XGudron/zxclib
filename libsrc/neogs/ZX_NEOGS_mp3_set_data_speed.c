#include "zx_neogs.h"

void ZX_NEOGS_mp3_set_data_speed(bool half_speed) { ZX_NEOGS_sctrl_set_bit(ZX_NEOGS_SERIAL_MD_HLF_MASK, half_speed); }
