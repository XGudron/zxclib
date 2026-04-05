#include "zx_netusb.h"

void ZX_NETUSB_net_set_set_port_mapping_addr(uint8_t addr) {
    zx_netusb_net_io_mapping_register = addr & 0xF;
}
