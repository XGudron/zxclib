#include "zx_neogs.h"

bool ZX_NEOGS_sd_is_write_protected(void) {
	uint8_t status = ZX_GS_in_from_any_port(ZX_NEOGS_INNER_PORT_SERIAL_STATUS);
	return (status & ZX_NEOGS_SERIAL_SD_WP_MASK) != 0;
}
