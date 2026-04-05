#include "zx_netusb.h"

void ZX_NETUSB_net_toggle_rom_adressing(bool enabled) {
    zx_netusb_control_register = zx_netusb_control_register & ~(0x4) | (enabled << 2);
}