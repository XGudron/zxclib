#include "zx_48k.h"

void ZX_set_im2_handler(void (*handler)(void)) {
    for(uint16_t i = 1; i < 257; i += 2) {
        interrupt_vector_table[i] = (uint16_t)handler;
        interrupt_vector_table[i+1] = (uint16_t)handler >> 8;
    }

    __asm
        di
        ; Устанавливаем адрес (старший байт) таблицы векторов в регистр I
        ld   a, #0xFD
        ld   i, a
        ; Устанавливаем режим прерывания IM2
        im   2
        ei
    __endasm;
}
