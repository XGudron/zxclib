	.module TTY_PUTF
	.globl sendchars,sendchar
	.area _CODE

_putf::
	push bc
	push ix
	push iy
	xor a
	ld b,a
	ld c,a
	cpir
	xor a
	sbc hl,de
	dec hl
	push hl
	call sendchars
	pop hl
	pop iy
	pop ix
	pop bc
	ret
