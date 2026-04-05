#include "zx_netusb.h"

bool ZX_NETUSB_usb_get_powered(void) {
    return (zx_netusb_control_register & 0x80) >> 7;
}
