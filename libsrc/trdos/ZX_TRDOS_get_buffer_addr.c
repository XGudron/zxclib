#include <zx_trdos.h>

uint16_t ZX_TRDOS_get_buffer_addr(void) { return *((uint16_t *)ZX_TRDOS_DESTINATION_BUFFER); }
