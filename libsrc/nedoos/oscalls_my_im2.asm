	.module	my_im2
	.area _INTJP
	.ds 3
	.area _INTTABLE
	.ds 257
	.area _CODE

_my_im2_init::
	di
	ld a,#0xc3
	ld (INTJP),a
	ld (INTJP+1),de
	ld a,#>(INTTABLE)
	ld i,a
	inc a
	ld hl,#(INTTABLE-1)
tloop:
	inc hl
	ld (hl),#>(INTJP)
	cp h
	jr nz,tloop
	im 2
	ret
