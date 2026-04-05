#include "zx_neogs.h"

void ZX_NEOGS_set_memory_page(uint8_t page_num) { ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_MEM_PAGE, page_num & 0x3F); }
