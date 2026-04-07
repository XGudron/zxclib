	.module CLEARC000
	.include "sysdefs.asm"
	.area _CODE

_CLEARC000::	
	push hl
	push bc
	push de
	ld bc, #6912
	ld hl, #0xc000
clearloop:
	ld (hl), #0
	inc hl
	dec bc
	ld a, b
	or c
	jp nz, clearloop
	pop de
	pop bc
	pop hl
	ret
