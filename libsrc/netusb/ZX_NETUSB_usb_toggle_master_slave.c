#include "zx_netusb.h"

void ZX_NETUSB_usb_toggle_master_slave(bool master) {
    zx_netusb_control_register = zx_netusb_control_register & ~(0x40) | (master << 6);
}
