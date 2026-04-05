#include "zx_gs.h"

void ZX_GS_exit_covox_mode(void) {
	ZX_GS_reset_flags(); // Exit covox mode
}
