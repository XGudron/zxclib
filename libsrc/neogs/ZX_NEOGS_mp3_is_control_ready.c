#include "zx_neogs.h"

bool ZX_NEOGS_mp3_is_control_ready(void) {
	uint8_t status = ZX_GS_in_from_any_port(ZX_NEOGS_INNER_PORT_SERIAL_STATUS);
	return (status & ZX_NEOGS_SERIAL_MC_RDY_MASK) != 0;
}
