	.module rst0x08
	.include "sysdefs.asm"
	.area _CODE

_rst0x08::	
	push ix
	push iy
	rst 0x08
	pop iy
	pop ix
	ld a,c
	ret
