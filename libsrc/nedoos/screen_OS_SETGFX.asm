	.module OS_SETGFX
	.include "sysdefs.asm"
	.area _CODE

_OS_SETGFX::
	ld e, a
	push bc
	ld c,#CMD_SETGFX ;e=0:EGA, e=2:MC, e=3:6912, e=6:text ;+8 for noturbo ;+0x80 for auto screen pages keeping ;+SET FOCUS ;e=-1: disable gfx (out: e=old gfxmode)
	push ix
	push iy
	call BDOS
	pop iy
	pop ix
	pop bc
	ld a, e
	ret	
