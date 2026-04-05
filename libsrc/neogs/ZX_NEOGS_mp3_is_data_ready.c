#include "zx_neogs.h"

bool ZX_NEOGS_mp3_is_data_ready(void) {
	uint8_t status = ZX_GS_in_from_any_port(ZX_NEOGS_INNER_PORT_SERIAL_STATUS);
	return (status & ZX_NEOGS_SERIAL_MD_DRQ_MASK) != 0;
}
