	.module OS_SETXYW
	.include "sysdefs.asm"
	.area _CODE

_OS_SETXYW::
	ex de, hl
	push bc
    ld c,#CMD_SETXY	;de=yx ;SET CURSOR POSITION
	push ix
	push iy
	call BDOS
	pop iy
	pop ix
	pop bc
	ret	
