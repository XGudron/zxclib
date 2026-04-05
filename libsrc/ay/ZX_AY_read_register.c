#include "zx_ay.h"

uint8_t ZX_AY_read_register(zx_ay_register_t reg) {
	ZX_ay_reg_port = reg;   // Выбор регистра
	return ZX_ay_data_read; // Чтение данных
}
