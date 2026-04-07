#ifndef NEDOOS_AUART_H
#define NEDOOS_AUART_H

#include <stdint.h>

void uart_init(uint8_t divisor);
void uart_write(uint8_t data);
void uart_startrts(void);
void uart_stoprts(void);
void uart_flashrts(void);
uint8_t uart_read(void);
uint8_t uart_queue(void);
void uart_delay10k(void);

#endif
