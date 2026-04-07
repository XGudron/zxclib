	.module OS_GETMOUSE
	.area _CODE

_OS_GETMOUSE::
	push ix
	push iy
    rst 0x08	;out: a=key (NOKEY=no key), de=mouse position (y,x), l=mouse buttons (bits 0,1,2: 0=pressed)+mouse wheel (bits 7..4), h=high bits of key|register, bc=keynolang, lx=kempston joystick, nz=no focus (mouse position=0, ignore it!)
	pop iy
	pop ix
	ld h,c
	ret 
