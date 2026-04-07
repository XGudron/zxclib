	.module OS_GETPAGEOWNER	;e=page ;out: e=owner id (0=free, 0xff=system)
	.include "sysdefs.asm"
	.area _CODE

_OS_GETPAGEOWNER::
	ld e, a
    push bc
	push ix
	push iy
	ld c,#CMD_GETPAGEOWNER
	call BDOS
	LD a, e
	pop iy
	pop ix
    pop bc
	ret
	