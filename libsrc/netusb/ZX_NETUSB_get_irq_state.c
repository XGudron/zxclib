#include "zx_netusb.h"

bool ZX_NETUSB_get_irq_state(void) {
    return (zx_netusb_irq_n_reset_register & 0x80) >> 7;
}
