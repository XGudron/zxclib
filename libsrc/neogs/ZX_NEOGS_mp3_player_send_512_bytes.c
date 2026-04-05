#include "zx_neogs.h"

void ZX_NEOGS_mp3_player_send_512_bytes(const uint8_t *data) {
	zx_gs_command_register = ZX_NEOGS_MP3_DATA_SEND_512_BYTES;

	for (uint16_t i = 0; i < 512; i++) {
		zx_gs_output_register = data[i];
		ZX_GS_wait_data_available();
	}
}
