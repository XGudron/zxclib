#ifndef NEDOOS_OSCALLS_H
#define NEDOOS_OSCALLS_H

#include <stdint.h>

void os_initstdio(void);

void OS_CLS(uint8_t color);
unsigned int OS_GETXY(void);
uint8_t OS_GETATTR(void);
void OS_PRATTR(uint8_t attribute);
void OS_SCROLLUP(uint16_t xy, uint16_t wh);
uint8_t OS_SETGFX(uint8_t mode); // ;e=0:EGA, e=2:MC, e=3:6912, e=6:text ;+8 for noturbo ;+0x80 for auto screen pages keeping ;+SET FOCUS ;e=-1: disable gfx (out: e=old gfxmode)
void OS_SETXY(uint8_t x, uint8_t y);
void OS_SETXYW(uint16_t w);

void bdosputchar(char chr);
void bdosprint(char *str);
void bdosputs(char *str);

////////////////////

void OS_DROPAPP(unsigned char id);
unsigned long OS_GETAPPMAINPAGES(unsigned char id);
unsigned char OS_GETPAGEOWNER(unsigned char id);
void YIELD(void);
void OS_SETCOLOR(unsigned char color);
void OS_SETMUSIC(void (*play)(void), unsigned char pg);
long time(void); // Alone Coder

// Kulich Area
struct diskOp {
	unsigned char drive;
	void *BufAdr;
	unsigned long sector;
	unsigned char count;
};

signed long OS_GETKEY(void);
unsigned long OS_GETMOUSE(void);

unsigned int OS_READSECTORS(struct diskOp *);
unsigned int OS_WRITESECTORS(struct diskOp *);
unsigned long OS_GETTIME(void);
unsigned int OS_NEWPAGE(void);
unsigned char OS_DELPAGE(char pageNumber);
unsigned int OS_GETSCR0(void);
unsigned int OS_GETSCR1(void);
void OS_SETBORDER(unsigned char color);
unsigned int OS_CHDIR(unsigned char *trgPathPtr);
unsigned int OS_GETPATH(unsigned int curPathPtr);
unsigned int OS_SETSYSDRV(void);                  
unsigned int OS_NEWAPP(unsigned int trgPathPtr);
unsigned int OS_RUNAPP(unsigned char pId);
unsigned int OS_WAITPID(unsigned char pId);
unsigned int OS_HIDEFROMPARENT(void);
unsigned long OS_STARTAPP(unsigned long appParamsPtr);   
unsigned int OS_RENAME(unsigned char *oldName, unsigned char *newName); 
                                                                        
unsigned int OS_DELETE(unsigned char *fileName);                        
void OS_DIHALT(void);
void OS_SETPG8000(unsigned char page);
void OS_SETPGC000(unsigned char page);
void OS_SETSCREEN(unsigned char screen);
// End of Kulich area

void SETPG32KHIGH(unsigned char page);

union APP_PAGES {
	unsigned long l;
	struct {
		unsigned char window_3;
		unsigned char window_2;
		unsigned char window_1;
		unsigned char window_0;
		unsigned char pId;
		unsigned char error;
		unsigned char f;
	} pgs;
};
unsigned long OS_GETMAINPAGES(void);
unsigned int OS_GETCONFIG(void);
unsigned int os_reserv_1(void *);
unsigned int _low_level_get(void);
char *cgets(char *str);
void conv1251to866(unsigned char *bufer);

void exit(int e);
unsigned char scrredraw(void);

#define MOUSE_BUTTON_BIT_LMB 0x01
#define MOUSE_BUTTON_BIT_RMB 0x02

extern unsigned char errno;
extern unsigned int mouse_yx;
extern unsigned char mouse_x;
extern unsigned char mouse_y;
extern unsigned char mouse_btns;
extern unsigned char t1251to866[128];

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

#endif
