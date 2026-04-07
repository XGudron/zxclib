	.module OS_PRATTR
	.include "sysdefs.asm"
	.area _CODE

_OS_PRATTR::
	ld e, a
	push bc
	ld c,#CMD_PRATTR ;OBSOLETE ;e=color byte ;DRAW ATTR AT CURSOR POSITION
	push ix
	push iy
	call BDOS
	pop iy
	pop ix
	pop bc
	ret	
