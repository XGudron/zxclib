#include <zx_trdos.h>

uint8_t ZX_TRDOS_get_sector_num(void) { return *((uint8_t *)ZX_TRDOS_CURRENT_SECTOR); }
