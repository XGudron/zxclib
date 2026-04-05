#pragma codeseg BANK0
#include "zxclib.h"
#include <stdint.h>

static void bank0_inner_call(void);

void bank0_test_call(void) __banked {
	ZX_EVO_print("Hello from bank 0\r");
	bank0_inner_call();
}

static void bank0_inner_call(void) { ZX_EVO_print("Another hello from bank 0\r"); }
