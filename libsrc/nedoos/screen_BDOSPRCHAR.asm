	.module BDOSPRCHAR
	.area _CODE

_bdosputchar::
    push bc
	push de
	push ix
	push iy
	rst 0x10
	pop iy
	pop ix
	pop hl
    pop bc
	ret
