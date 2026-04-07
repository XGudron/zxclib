	.module OS_SETPGC000
	.include "sysdefs.asm"
	.area _CODE
	
_OS_SETPGC000::
	push bc
	push ix
	push iy
	rst 0x28
	pop iy
	pop ix
	pop bc
	ret
