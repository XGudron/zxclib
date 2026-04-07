	.module OS_GETSCR0	
	.include "sysdefs.asm"
	.area _CODE

_OS_GETSCR0::
	ld a,(user_scr0_high)
	ld d,a
	ld a,(user_scr0_low)
	ld e, a
	ret
