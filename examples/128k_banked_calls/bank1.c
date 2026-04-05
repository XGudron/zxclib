#pragma codeseg BANK1
#include "zxclib.h"
#include <stdint.h>

static void bank1_inner_call(void);

void bank1_test_call(void) __banked {
	ZX_48K_print_at(0, 12, "Hello from bank 1");
	bank1_inner_call();
}

static void bank1_inner_call(void) { ZX_48K_print_at(0, 13, "Another hello from bank 1"); }
