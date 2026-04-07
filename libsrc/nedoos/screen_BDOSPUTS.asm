	.module BDOSPUTS
	.area _CODE

_bdosputs::
	push ix
	push iy
	push hl
ploop:
	pop hl
	ld a,(hl)
	or a
	jr z,pexit
	inc hl
	push hl
	rst 0x10
	jr ploop
pexit:
	ld a,#'\r'
	rst 0x10
	ld a,#'\n'
	rst 0x10
	ld hl,#0x0000
	pop iy
	pop ix
	ret
	