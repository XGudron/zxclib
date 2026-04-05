#include "zx_neogs.h"

uint8_t ZX_NEOGS_sd_wait_response(uint8_t expected_value, uint8_t timeout) {
	while (timeout--) {
		ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_SD_SEND, 0xFF);
		// Программные паузы для синхронизации
		__asm__("nop");
		__asm__("nop");
		uint8_t response = ZX_GS_in_from_any_port(ZX_NEOGS_INNER_PORT_SD_READ);
		if (response == expected_value) {
			return 1;
		}
	}
	return 0;
}
