	.module OS_RUNAPP
	.include "sysdefs.asm"
	.area _CODE

_OS_RUNAPP::	
	ld e, a
	push hl
	push bc
	push ix
	push iy
	ld c,#CMD_RUNAPP	;e=id ;ACTIVATE DISABLED APP
	call BDOS
	pop iy
	pop ix
    pop bc
	pop hl
	ex de, hl
	ret
