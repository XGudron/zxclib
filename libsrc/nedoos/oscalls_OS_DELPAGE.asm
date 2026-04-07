	.module OS_DELPAGE	;out: a=0 (OK)/!=0 (fail), e=page
	.include "sysdefs.asm"
	.area _CODE

_OS_DELPAGE::
	ld e, a
    push bc
	push hl
	ld c,#CMD_DELPAGE ;e=page ;GIVE SOME PAGE BACK TO THE OS
	push ix
	push iy
	call BDOS
	pop iy
	pop ix
    pop hl
	pop bc
	ret
