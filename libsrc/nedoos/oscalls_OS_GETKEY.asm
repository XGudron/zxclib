	.module OS_GETKEY
	.area _CODE
	
_OS_GETKEY::
	push ix
	push iy
    rst 0x08	;out: a=key (NOKEY=no key), de=mouse position (y,x), l=mouse buttons (bits 0,1,2: 0=pressed)+mouse wheel (bits 7..4), h=high bits of key|register, bc=keynolang, lx=kempston joystick, nz=no focus (mouse position=0, ignore it!)
	pop iy
	pop ix
	ld l,a
	ld h,c
	ld de,#0x8000
	jp nz, focusFalse
	ld de,#0x0000
focusFalse:
	ret 
