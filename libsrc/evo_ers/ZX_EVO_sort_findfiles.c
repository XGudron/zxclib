#include "zx_evo_ers.h"

void ZX_EVO_sort_findfiles(void) {
	// TODO узнать параметры функции и её результат

	__asm
	RST 8
	.db 0x52
	__endasm;
}
