	.module TTYPUTCHAR
	.globl sendchar
	.area _CODE

_ttyputchar::
	push bc
	push hl
	push ix
	push iy
	ld a,l
	call sendchar
	ld de,#0x0000
	pop iy
	pop ix
	pop hl
	pop bc
	ret
