	.module OS_GETSCR1
	.include "sysdefs.asm"
	.area _CODE

_OS_GETSCR1::
	ld a,(user_scr1_high)
	ld d,a
	ld a,(user_scr1_low)
	ld e,a
	ret
