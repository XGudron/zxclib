	.module BDOSPRINT
	.area _CODE

_bdosprint::
    push bc
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
	pop iy
	pop ix
    pop bc
	ret
