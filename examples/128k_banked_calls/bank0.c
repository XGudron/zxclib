#pragma codeseg BANK0
#include "zxclib.h"
#include <stdint.h>

static void bank0_inner_call(void);

void bank0_test_call(void) __banked {
	ZX_48K_print_at(0, 10, "Hello from bank 0");
	bank0_inner_call();
}

static void bank0_inner_call(void) { ZX_48K_print_at(0, 11, "Another hello from bank 0"); }
