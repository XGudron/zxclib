	.module OS_CLS
	.include "sysdefs.asm"
	.area _CODE

_OS_CLS::
	ld e, a
	push bc
	ld c,#CMD_CLS ;e=color byte
	push ix
	push iy
	call BDOS
	pop iy
	pop ix
	pop bc
	ret	
