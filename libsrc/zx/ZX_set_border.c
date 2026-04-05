#include "zx_48k.h"

void ZX_set_border(zx_color_t color) {
	static __sfr __at 0xFE border_port;
	border_port = color;
}
