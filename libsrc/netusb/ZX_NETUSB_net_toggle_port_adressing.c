#include "zx_netusb.h"

void ZX_NETUSB_net_toggle_port_adressing(bool enabled) {
    zx_netusb_control_register = zx_netusb_control_register & ~(0x10) | (enabled << 4);
}
