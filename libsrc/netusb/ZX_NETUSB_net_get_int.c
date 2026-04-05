#include "zx_netusb.h"

bool ZX_NETUSB_net_get_int(void) {
    return (zx_netusb_irq_n_reset_register & 0x1);
}
