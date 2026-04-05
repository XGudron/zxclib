#include "zx_netusb.h"

void ZX_NETUSB_net_set_rom_adressing_window(uint8_t window) {
    zx_netusb_control_register = zx_netusb_control_register & ~(0x3) | window;
}
