#include "zx_neogs.h"

void ZX_NEOGS_mp3_send_end_silence(void) {
	for (uint16_t i = 0; i < 2048; i++) {
		ZX_NEOGS_mp3_send_data_byte(0);
	}
}
