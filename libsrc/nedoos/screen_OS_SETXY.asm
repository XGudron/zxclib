	.module OS_SETXY
	.include "sysdefs.asm"
	.area _CODE

_OS_SETXY::
	ld d,a
	ld e,l
	push bc
	ld c,#CMD_SETXY	;de=yx ;SET CURSOR POSITION
	push ix
	push iy
	call BDOS
	pop iy
	pop ix
	pop bc
	ret	
