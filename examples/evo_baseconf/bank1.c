#pragma codeseg BANK1
#include "zxclib.h"
#include <stdint.h>

static void bank1_inner_call(void);

void bank1_test_call(void) __banked {
	ZX_EVO_print("Hello from bank 1\r");
	bank1_inner_call();
}

static void bank1_inner_call(void) { ZX_EVO_print("Another hello from bank 1\r"); }
