#ifndef NEDOOS_OSFS_H
#define NEDOOS_OSFS_H

#include <stdint.h>

typedef uint16_t FILE;

#ifndef FILINFO_TYPE
typedef struct {
	unsigned long int fsize;  /* File size */
	unsigned int fdate;       /* Last modified date */
	unsigned int ftime;       /* Last modified time */
	unsigned char fattrib;    /* Attribute */
	unsigned char fname[13];  /* Short file name (8.3 format) */
	unsigned char lfname[64]; /* Pointer to the LFN buffer */
} FILINFO;
#endif

extern uint8_t errno;
// extern uint8_t syspath[8];

uint8_t *fs_get_err_str(void);

FILE *OS_CREATEHANDLE(uint8_t *path, uint8_t flags);

uint8_t OS_READDIR(FILINFO *fileinfo);
uint8_t OS_OPENDIR(uint8_t *path);
uint8_t OS_DELETE(uint8_t * path);
uint8_t OS_MKDIR(uint8_t *path);
uint8_t OS_CHDIR(const uint8_t *path);
uint8_t OS_CHDRV(uint8_t drive);

uint8_t OS_GETFILINFO(uint8_t *path, FILINFO *fileinfo);
void OS_SEEKHANDLE(FILE *hnd, uint32_t offset);
FILE *OS_OPENHANDLE(uint8_t *path, uint8_t flags);
uint16_t OS_CLOSEHANDLE(FILE *hnd);

uint8_t OS_SETSYSDRV(void);
uint32_t OS_GETFILESIZE(FILE *hnd);
uint8_t *OS_GETPATH(uint8_t *path);
uint16_t OS_READHANDLE(uint8_t *buffer, FILE *hnd, uint16_t count);
uint16_t OS_WRITEHANDLE(uint8_t *buffer, FILE *hnd, uint16_t count);

#endif
