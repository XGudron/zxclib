	.module OS_HIDEFROMPARENT
	.include "sysdefs.asm"
	.area _CODE

_OS_HIDEFROMPARENT::
	push bc
	push ix
	push iy
	ld c,#CMD_HIDEFROMPARENT ;for tasks with their own screen handling ;hl=result
	call BDOS
	pop iy
	pop ix
    pop bc
	ex de, hl
	ret
