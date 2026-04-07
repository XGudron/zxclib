	.module OS_GETMAINPAGES
    .globl errno
 	.include "sysdefs.asm"
	.area _CODE

_OS_GETAPPMAINPAGES::
	ld e, a
    ld c,#CMD_GETAPPMAINPAGES ;e=id ;out: d,e,h,l=pages in 0000,4000,8000,c000, c=flags, a=error
    jr l1
_OS_GETMAINPAGES::
	ld c,#CMD_GETMAINPAGES ;out: d,e,h,l=pages in 0000,4000,8000,c000, c=flags, b=id
l1:
	push ix
 	push iy
	call BDOS
 	pop iy
 	pop ix
 	LD (errno), a
 	ret
