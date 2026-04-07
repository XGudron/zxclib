	.module OS_GETCONFIG
	.include "sysdefs.asm"
	.area _CODE

_OS_GETCONFIG::
    push bc
	ld c,#CMD_GETCONFIG ;out: H=system drive, L= 1-Evo 2-ATM2 3-ATM3 6-p2.666, E=pgsys(system page), D= TR-DOS page, IXBC=SVN revision
	push ix
	push iy
	call BDOS
	pop iy
	pop ix
    pop bc
	ex de, hl
	ret
