#include "zx_neogs.h"

void ZX_NEOGS_set_memory_page_extended_low(uint8_t page_num, uint8_t half_page) {
	uint8_t value = (page_num & 0x3F) | ((half_page & 1) << 7);
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_MEM_PAGE, value);
}
