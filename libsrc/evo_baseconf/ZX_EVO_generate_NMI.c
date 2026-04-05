#include "zx_evo_baseconf.h"

void ZX_EVO_generate_NMI(void) {
	zx_evo_xxBF_port |= 0x08;
	zx_evo_xxBF_port &= ~(0x08);
}
