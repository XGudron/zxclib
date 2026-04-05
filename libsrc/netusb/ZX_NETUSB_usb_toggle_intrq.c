#include "zx_netusb.h"

void ZX_NETUSB_usb_toggle_intrq(bool enabled) {
    zx_netusb_irq_n_reset_register = zx_netusb_irq_n_reset_register & ~(0x8) | (enabled << 3);
}
