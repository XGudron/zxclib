	.module OS_DROPAPP
	.include "sysdefs.asm"
	.area _CODE

_OS_DROPAPP::	
	ld e, a
	ld c,#CMD_DROPAPP ;e=id ; hl=result
	push ix
	push iy
	call BDOS
	pop iy
	pop ix
	ex de, hl
	ret
