	.module OS_SETCOLOR
	.include "sysdefs.asm"
	.area _CODE

_OS_SETCOLOR::
	ld e, a
	push bc
	push hl
	push ix
	push iy
    ld c,#CMD_SETCOLOR
	call BDOS
	pop iy
	pop ix
	pop bc
	pop hl
	ret
