	.module TTYGETKEY_NE
	.globl receivekey,exit
	.include "sysdefs.asm"
	.area _CODE

_ttygetkey_ne::
	push bc
	push hl
	push ix
	push iy
	ld c,#CMD_YIELD
	call BDOS
	call receivekey
	ld e,a
	ld d,#0
	pop iy
	pop ix
	pop hl
	pop bc
	ret
	