#include "zx_netusb.h"

void ZX_NETUSB_net_toggle_int(bool enabled) {
    zx_netusb_irq_n_reset_register = zx_netusb_irq_n_reset_register & ~(0x4) | (enabled << 2);
}
