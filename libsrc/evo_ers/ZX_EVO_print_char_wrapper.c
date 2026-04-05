#include "zx_evo_ers.h"

void ZX_EVO_print_char_wrapper(char chr) {
	if (chr == '\r') {
		ZX_EVO_print("\r");
		return;
	}

	ZX_EVO_print_char(chr);
}
