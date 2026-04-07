	.module OS_SCROLLUP
	.include "sysdefs.asm"
	.area _CODE

_OS_SCROLLUP::
	ex de, hl
	push bc
	ld c,#CMD_SCROLLUP ;de=topyx, hl=hgt,wid ;x, wid even ;TEXTMODE ONLY
	push ix
	push iy
	call BDOS
	pop iy
	pop ix
	pop bc
	ret	
