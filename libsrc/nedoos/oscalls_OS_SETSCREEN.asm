	.module OS_SETSCREEN
	.include "sysdefs.asm"
	.area _CODE

_OS_SETSCREEN::
	ld e, a
	push bc
	push hl
	push ix
	push iy
	ld c,#CMD_SETSCREEN	 ;e=screen=0..1
	call BDOS
	pop iy
	pop ix
	pop hl
	pop bc
	ret
