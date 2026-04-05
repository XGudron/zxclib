#include "zx_netusb.h"

void ZX_NETUSB_net_toggle_invert_addr0(bool enabled) {
    zx_netusb_control_register = zx_netusb_control_register & ~(0x8) | (enabled << 3);
}
