	.module OS_SETPG8000
	.include "sysdefs.asm"
	.area _CODE

_OS_SETPG8000::
	push bc
	push ix
	push iy
	rst 0x20
	pop iy
	pop ix
	pop bc
	ret
