	.module TTYPRINTN
	.globl sendchars
	.area _CODE

_printn::
	push ix
	push iy
	ex de, hl
	call sendchars
	pop iy
	pop ix
	ret
