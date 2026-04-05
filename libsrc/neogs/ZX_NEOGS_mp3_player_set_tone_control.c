#include "zx_neogs.h"

void ZX_NEOGS_mp3_player_set_tone_control(uint8_t treble_freq, int8_t treble_level, uint8_t bass_freq, uint8_t bass_level, uint8_t change_treble, uint8_t change_bass_freq,
                                          uint8_t change_treble_level, uint8_t change_bass_level, uint8_t treble_up) {
	uint8_t control_byte = 0;

	// Бит 6: изменение уровня BASS
	if (change_bass_level) {
		control_byte |= 0x40;
	}
	// Бит 4: изменение частоты BASS
	if (change_bass_freq) {
		control_byte |= 0x10;
	}
	// Бит 2: изменение уровня TREBLE
	if (change_treble_level) {
		control_byte |= 0x04;
	}
	// Бит 0: изменение частоты TREBLE
	if (change_treble) {
		control_byte |= 0x01;
	}

	// Биты 7,5,3,1: увеличение на единицу
	if (treble_up) {
		control_byte |= 0x80; // Treble частота
		control_byte |= 0x20; // Treble уровень
		control_byte |= 0x08; // Bass частота
		control_byte |= 0x02; // Bass уровень
	}

	zx_gs_data_register = control_byte;
	zx_gs_command_register = ZX_NEOGS_MP3_DATA_SET_TONE_CONTROL;
	ZX_GS_wait_command_ready();

	// Отправка параметров
	zx_gs_data_register = treble_freq;
	ZX_GS_wait_data_ready();
	zx_gs_data_register = treble_level;
	ZX_GS_wait_data_ready();
	zx_gs_data_register = bass_freq;
	ZX_GS_wait_data_ready();
	zx_gs_data_register = bass_level;
	ZX_GS_wait_data_ready();
}
