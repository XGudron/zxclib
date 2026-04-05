#include "zx_neogs.h"

uint8_t ZX_NEOGS_bootloader_set_get_cpu_frequency(uint8_t frequency) {
	zx_gs_data_register = frequency;
	zx_gs_command_register = ZX_NEOGS_BOOTLOADER_CMD_SET_GET_CPU_FREQUENCY;
	ZX_GS_wait_command_ready();

	// Возвращаем результат только при запросе текущей частоты
	if (frequency & ZX_NEOGS_BOOTLOADER_CPU_FREQ_GET) {
		return zx_gs_data_register;
	}
	return 0;
}
