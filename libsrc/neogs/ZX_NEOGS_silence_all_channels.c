#include "zx_neogs.h"

void ZX_NEOGS_silence_all_channels(void) {
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_1, 0);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_2, 0);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_3, 0);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_4, 0);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_5, 0);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_6, 0);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_7, 0);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_VOLUME_8, 0);
}
