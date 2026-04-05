#include "zx_netusb.h"

void ZX_NETUSB_toggle_zxbus_int(bool enabled) {
    zx_netusb_irq_n_reset_register = zx_netusb_irq_n_reset_register & ~(0x40) | (enabled << 6);
}
