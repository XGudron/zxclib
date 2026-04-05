#include "zx_neogs.h"

void ZX_NEOGS_mp3_set_reset(bool reset_active) { ZX_NEOGS_sctrl_set_bit(ZX_NEOGS_SERIAL_MC_XRS_MASK, !reset_active); }
