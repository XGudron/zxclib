#ifndef NEDOOS_GRAPHIC_H
#define NEDOOS_GRAPHIC_H

#include <stdint.h>

void CLEARC000(void);
void CLEARC000FAST(void);
void OS_HALT(void);
uint8_t rst0x08(void);
uint8_t viewScreen6912(uint16_t bufAdr, uint16_t ints_time);
uint16_t viewScreen6912NoKeyGraph(uint32_t bufIntBrd);

#endif
