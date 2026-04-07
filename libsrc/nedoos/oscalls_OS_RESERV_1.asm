	.module OS_RESERV_1
	.include "sysdefs.asm"
	.area _CODE

_os_reserv_1::
	ex de, hl
	push bc
	push ix
	push iy
    ld c,#CMD_RESERV_1
	call BDOS
	pop iy
	pop ix
	pop bc
	ex de, hl
	ret	
	