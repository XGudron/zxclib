	.module TTYGETKEY
	.globl receivekey,exit
	.include "sysdefs.asm"
	.area _CODE

_ttygetkey::
	push bc
	push hl
	push ix
	push iy
	ld c,#CMD_YIELD
	call BDOS
	call receivekey
	cp #key_esc
	jp z,exit
	ld e,a
	ld d,#0
	pop iy
	pop ix
	pop hl
	pop bc
	ret
