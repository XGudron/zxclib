#include "zx_evo_baseconf.h"

uint8_t ZX_EVO_keyboard_read(uint8_t half_row) {
	switch (half_row) {
	case 0:
		return zx_evo_FEFE_port & 0x1F;
	case 1:
		return zx_evo_FDFE_port & 0x1F;
	case 2:
		return zx_evo_FBFE_port & 0x1F;
	case 3:
		return zx_evo_F7FE_port & 0x1F;
	case 4:
		return zx_evo_EFFE_port & 0x1F;
	case 5:
		return zx_evo_DFFE_port & 0x1F;
	case 6:
		return zx_evo_BFFE_port & 0x1F;
	case 7:
		return zx_evo_7FFE_port & 0x1F;
	}
	return 0xFF;
}
