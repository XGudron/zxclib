#include "zx_neogs.h"

bool ZX_NEOGS_spi_wait_ready(uint8_t timeout) {
	while (timeout--) {
		uint8_t status = ZX_GS_in_from_any_port(ZX_NEOGS_INNER_PORT_SERIAL_STATUS);
		if (status & ZX_NEOGS_SERIAL_MC_RDY_MASK) {
			return 1;
		}
	}
	return 0;
}
