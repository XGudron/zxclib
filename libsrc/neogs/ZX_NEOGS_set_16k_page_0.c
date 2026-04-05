#include "zx_neogs.h"

void ZX_NEOGS_set_16k_page_0(uint8_t page_num) { ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_RAM_WINDOW_0, page_num); }
