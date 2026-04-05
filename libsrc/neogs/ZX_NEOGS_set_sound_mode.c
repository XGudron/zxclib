#include "zx_neogs.h"

void ZX_NEOGS_set_sound_mode(uint8_t mode) {
	uint8_t value = ZX_GS_in_from_any_port(ZX_NEOGS_INNER_PORT_CONFIG0);

	// Сбрасываем биты режимов
	value &= ~(ZX_NEOGS_CONFIG_8_CHANNELS_MASK | ZX_NEOGS_CONFIG_CHANNELS_PANNING);

	switch (mode) {
	case 1: // 8 каналов
		value |= ZX_NEOGS_CONFIG_8_CHANNELS_MASK;
		break;
	case 2: // 4 канала с паннингом
		value |= ZX_NEOGS_CONFIG_CHANNELS_PANNING;
		break;
	case 0: // 4 канала (по умолчанию)
	default:
		// Биты уже сброшены
		break;
	}

	ZX_GS_out_to_any_port(ZX_NEOGS_INNER_PORT_CONFIG0, value);
}
