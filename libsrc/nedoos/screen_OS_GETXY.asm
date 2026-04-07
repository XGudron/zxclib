	.module OS_GETXY
	.include "sysdefs.asm"
	.area _CODE

_OS_GETXY::
	push bc
	ld c,#CMD_GETXY	;de=yx ;GET CURSOR POSITION
	push ix
	push iy
	call BDOS
	pop iy
	pop ix
	pop bc
	ret
