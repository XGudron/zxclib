#ifndef NEDOOS_TTY_H
#define NEDOOS_TTY_H

#include <stdint.h>

int ttyputchar(int ch);
int ttyputs(char *str);
uint16_t ttygetkey(void);
uint16_t ttygetkey_ne(void);
char *ttygets(char *str);
char *cgets(char *str);
char *gets(char *str);
void putcsi(char ch);
void putf(int ch);

#endif
