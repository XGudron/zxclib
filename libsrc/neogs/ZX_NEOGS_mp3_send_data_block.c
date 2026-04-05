#include "zx_neogs.h"

uint16_t ZX_NEOGS_mp3_send_data_block(const uint8_t *buffer, uint16_t size) {
	uint16_t sent = 0;
	while (sent < size) {
		ZX_NEOGS_mp3_send_data_byte(buffer[sent]);
		sent++;
	}
	return sent;
}
