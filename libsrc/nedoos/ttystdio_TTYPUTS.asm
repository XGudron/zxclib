	.module TTYPUTS
	.globl sendchars,sendchar
	.area _CODE
	
_ttyputs::
	ld d,h
	ld e,l
	xor a
	ld b,a
	ld c,a
	cpir
	xor a
	sbc hl,de
	dec hl
	call sendchars
	ld a,#'\r'
	call sendchar
	ld a,#'\n'
	call sendchar
	ld de,#0x0000
	ret
