#include "zx_netusb.h"

void ZX_NETUSB_net_toggle_reset(bool enabled) {
    zx_netusb_irq_n_reset_register = zx_netusb_irq_n_reset_register & ~(0x10) | ((!enabled) << 4);
}
