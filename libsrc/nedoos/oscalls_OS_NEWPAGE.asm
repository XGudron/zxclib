	.module OS_NEWPAGE	;out: a=0 (OK)/!=0 (fail), e=page
	.include "sysdefs.asm"
	.area _CODE

_OS_NEWPAGE::
    push bc
	ld c,#CMD_NEWPAGE ;out: a=0 (OK)/!=0 (fail), e=page
	push ix
	push iy
	call BDOS
	pop iy
	pop ix
    pop bc
	ld d,a			;error
	; e			;page 
	ret
