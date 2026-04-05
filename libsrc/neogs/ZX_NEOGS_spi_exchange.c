#include "zx_neogs.h"

uint8_t ZX_NEOGS_spi_exchange(uint8_t send_port, uint8_t read_port, uint8_t data) {
	ZX_GS_out_to_any_port(send_port, data);
	return ZX_GS_in_from_any_port(read_port);
}
