#include "zx_ay.h"

uint8_t ZX_AY_get_enable(void) {
	return ~ZX_AY_read_register(ZX_AY_REG_ENABLE); // low - enabled
}
