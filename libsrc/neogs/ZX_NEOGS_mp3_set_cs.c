#include "zx_neogs.h"

void ZX_NEOGS_mp3_set_cs(bool cs_active) { ZX_NEOGS_sctrl_set_bit(ZX_NEOGS_SERIAL_MC_NCS_MASK, !cs_active); }
