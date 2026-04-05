#include "zx_evo_baseconf.h"

void ZX_EVO_set_video_mode(zx_evo_video_mode_t mode) {
	switch (mode) {
	case ZX_EVO_VIDEOMODE_ZX_STANDARD:
		ZX_EVO_write_port_xx77((ZX_EVO_lastvalue_port_xx77 & 0xF8) | 0b011);
		zx_evo_EFF7_noshadow_port = (ZX_EVO_lastvalue_port_EFF7 & ~(1 << 0) & ~(1 << 5));
		break;
	case ZX_EVO_VIDEOMODE_ZX_HW_MULTICOLOR:
		ZX_EVO_write_port_xx77((ZX_EVO_lastvalue_port_xx77 & 0xF8) | 0b011);
		zx_evo_EFF7_noshadow_port = ((ZX_EVO_lastvalue_port_EFF7 & ~(1 << 0)) | (1 << 5));
		break;
	case ZX_EVO_VIDEOMODE_ZX_256x192_16COLORS:
		ZX_EVO_write_port_xx77((ZX_EVO_lastvalue_port_xx77 & 0xF8) | 0b011);
		zx_evo_EFF7_noshadow_port = ((ZX_EVO_lastvalue_port_EFF7 & ~(1 << 5)) | (1 << 0));
		break;
	case ZX_EVO_VIDEOMODE_ATM_640x200_HW_MULTICOLOR:
		ZX_EVO_write_port_xx77((ZX_EVO_lastvalue_port_xx77 & 0xF8) | 0b010);
		zx_evo_EFF7_noshadow_port = (ZX_EVO_lastvalue_port_EFF7 & ~(1 << 0) & ~(1 << 5));
		break;
	case ZX_EVO_VIDEOMODE_ATM_320x200_16COLORS:
		ZX_EVO_write_port_xx77((ZX_EVO_lastvalue_port_xx77 & 0xF8) | 0b000);
		zx_evo_EFF7_noshadow_port = (ZX_EVO_lastvalue_port_EFF7 & ~(1 << 0) & ~(1 << 5));
		break;
	case ZX_EVO_VIDEOMODE_ATM_TEXT_80x25:
		ZX_EVO_write_port_xx77((ZX_EVO_lastvalue_port_xx77 & 0xF8) | 0b110);
		zx_evo_EFF7_noshadow_port = (ZX_EVO_lastvalue_port_EFF7 & ~(1 << 0) & ~(1 << 5));
		break;
	case ZX_EVO_VIDEOMODE_ATM_TEXT_80x25_ONEPAGE:
		ZX_EVO_write_port_xx77((ZX_EVO_lastvalue_port_xx77 & 0xF8) | 0b111);
		zx_evo_EFF7_noshadow_port = (ZX_EVO_lastvalue_port_EFF7 & ~(1 << 0) & ~(1 << 5));
		break;
	}
}
