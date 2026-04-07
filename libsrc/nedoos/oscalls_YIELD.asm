	.module YIELD
	.include "sysdefs.asm"
	.area _CODE

_YIELD::
	push bc
	push de
	push ix
	push iy
	ld c,#CMD_YIELD
	call BDOS
	pop iy
	pop ix
	pop de
	pop bc
	ret
	