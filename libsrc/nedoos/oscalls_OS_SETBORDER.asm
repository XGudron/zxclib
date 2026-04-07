	.module OS_SETBORDER
	.include "sysdefs.asm"
	.area _CODE

_OS_SETBORDER::
	ld e, a
	push bc
	push hl
	push ix
	push iy
    ld c,#CMD_SETBORDER ;e=0..15
	call BDOS
	pop iy
	pop ix
	pop hl
	pop bc
	ret
