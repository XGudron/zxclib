#include "zx_ay.h"

void ZX_AY_write_register(zx_ay_register_t reg, uint8_t data) {
	ZX_ay_reg_port = reg;    // Выбор регистра
	ZX_ay_data_write = data; // Запись данных
}
