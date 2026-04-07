	.module SETPG32KHIGH
	.include "sysdefs.asm"
	.area _CODE

_SETPG32KHIGH::
	push bc
	push ix
	push iy
	rst 0x28
	pop iy
	pop ix
	pop bc
	ret
