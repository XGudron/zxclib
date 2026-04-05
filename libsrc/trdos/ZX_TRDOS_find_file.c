#include <string.h>
#include <zx_trdos.h>

uint8_t ZX_TRDOS_find_file(char *filename, uint8_t type) {
	memcpy((volatile uint8_t *)ZX_TRDOS_FILESEARCH_FILENAME, filename, 8);
	*((volatile uint8_t *)ZX_TRDOS_FILESEARCH_TYPE) = type;
	*((volatile uint8_t *)ZX_TRDOS_FILESEARCH_CHECK_SIZE) = 9;

	__asm
		ld c, #0x0A
		call 0x3D13
	__endasm;

	return *((volatile uint8_t *)ZX_TRDOS_FILESEARCH_RESULT);
}
