#include "zx_netusb.h"

bool ZX_NETUSB_usb_get_intrq(void) {
    return (zx_netusb_irq_n_reset_register & 0x2) >> 1;
}
