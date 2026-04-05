#include <zx_trdos.h>

uint8_t ZX_TRDOS_get_drive_num(void) { return *((uint8_t *)ZX_TRDOS_SYSTEM_REGISTER) & 0x03; }
