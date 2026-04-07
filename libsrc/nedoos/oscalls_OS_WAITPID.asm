	.module OS_WAITPID-
	.include "sysdefs.asm"
	.area _CODE

_OS_WAITPID::
	ld e, a
	push bc
	push ix
	push iy
    ld c,#CMD_SETWAITING
	call BDOS
	ld c,#CMD_YIELD
	call BDOS
	ld c,#CMD_GETCHILDRESULT
	call BDOS
	pop iy
	pop ix
	pop bc
	ex de, hl
	ret
