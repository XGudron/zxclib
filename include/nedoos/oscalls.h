#ifndef NEDOOS_OSCALLS_H
#define NEDOOS_OSCALLS_H

#include <stdint.h>

#define INK_BLACK 0x00
#define INK_BLUE 0x01
#define INK_RED 0x02
#define INK_MAGENTA 0x03
#define INK_GREEN 0x04
#define INK_CYAN 0x05
#define INK_YELLOW 0x06
#define INK_WHITE 0x07
#define INK_WHITE_BRIGHT 0x47

#define PAPER_BLACK 0x00
#define PAPER_BLUE 0x08
#define PAPER_RED 0x10
#define PAPER_MAGENTA 0x18
#define PAPER_GREEN 0x20
#define PAPER_CYAN 0x28
#define PAPER_YELLOW 0x30
#define PAPER_WHITE 0x38

#define MOUSE_BUTTON_BIT_LMB 0x01
#define MOUSE_BUTTON_BIT_RMB 0x02

union APP_PAGES {
	uint32_t l;
	struct {
		uint8_t window_3;
		uint8_t window_2;
		uint8_t window_1;
		uint8_t window_0;
		uint8_t pId;
		uint8_t error;
		uint8_t f;
	} pgs;
};

struct diskOp {
	uint8_t drive;
	void *BufAdr;
	uint32_t sector;
	uint8_t count;
};

void os_initstdio(void);

void OS_CLS(uint8_t color);
uint16_t OS_GETXY(void);
uint8_t OS_GETATTR(void);
void OS_PRATTR(uint8_t attribute);
void OS_SCROLLUP(uint16_t xy, uint16_t wh);
uint8_t OS_SETGFX(uint8_t mode); // ;e=0:EGA, e=2:MC, e=3:6912, e=6:text ;+8 for noturbo ;+0x80 for auto screen pages keeping ;+SET FOCUS ;e=-1: disable gfx (out: e=old gfxmode)
void OS_SETXY(uint8_t x, uint8_t y);
void OS_SETXYW(uint16_t w);

void bdosputchar(char chr);
void bdosprint(char *str);
void bdosputs(char *str);
char bdosgetkey(void);

void exit(int16_t e);
uint16_t _low_level_get(void);
uint8_t scrredraw(void);
uint16_t os_reserv_1(void *);
uint32_t time(void);

extern uint8_t errno;
extern uint8_t t1251to866[128];
extern uint16_t mouse_yx;
extern uint8_t mouse_x;
extern uint8_t mouse_y;
extern uint8_t mouse_btns;

void conv1251to866(uint8_t *bufer);
uint8_t OS_DELPAGE(uint8_t pageNumber);
void OS_DIHALT(void);
void OS_DROPAPP(uint8_t id);
uint16_t OS_GETCONFIG(void);
uint32_t OS_GETKEY(void);
uint32_t OS_GETAPPMAINPAGES(uint8_t id);
uint32_t OS_GETMAINPAGES(void);
uint32_t OS_GETMOUSE(void);
uint8_t OS_GETPAGEOWNER(uint8_t id);
uint16_t OS_GETSCR0(void);
uint16_t OS_GETSCR1(void);
uint32_t OS_GETTIME(void);
uint16_t OS_HIDEFROMPARENT(void);
uint16_t OS_NEWAPP(uint16_t trgPathPtr);
uint16_t OS_NEWPAGE(void);
uint16_t OS_RENAME(uint8_t *oldName, uint8_t *newName); 
uint16_t OS_RUNAPP(uint8_t pId);
void OS_SETBORDER(uint8_t color);
void OS_SETCOLOR(uint8_t color);
void OS_SETMUSIC(void (*play)(void), uint8_t pg);
void OS_SETPG8000(uint8_t page);
void OS_SETPGC000(uint8_t page);
void OS_SETSCREEN(uint8_t screen);
uint16_t OS_WAITPID(uint8_t pId);
void SETPG32KHIGH(uint8_t page);
void YIELD(void);
uint16_t OS_READSECTORS(struct diskOp *);
uint16_t OS_WRITESECTORS(struct diskOp *);

#endif
