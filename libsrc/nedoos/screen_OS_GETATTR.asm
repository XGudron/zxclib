	.module OS_GETATTR
	.globl _OS_GFX_CALL
	.include "sysdefs.asm"
	.area _CODE

_OS_GETATTR::
	push bc
	ld c,#CMD_GETATTR ;DEPRECATED!!! ;out: a ;READ ATTR AT CURSOR POSITION
	push ix
	push iy
	call BDOS
	pop iy
	pop ix
	pop bc
	ret
