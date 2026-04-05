#include "zx_neogs.h"

void ZX_NEOGS_sd_set_cs(uint8_t cs_state) {
	uint8_t value;
	if (cs_state) {
		// Установить CS в 1 (высокий уровень)
		value = ZX_NEOGS_SET_N_CLR_MASK | ZX_NEOGS_SERIAL_SD_NCS_MASK;
	} else {
		// Установить CS в 0 (низкий уровень)
		value = ZX_NEOGS_SERIAL_SD_NCS_MASK;
	}
	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_SERIAL_CONTROL, value);
}
