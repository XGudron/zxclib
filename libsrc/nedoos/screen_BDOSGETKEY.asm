	.module BDOSGETKEY
	.globl scrredraw,exit,YIELD
	.include "sysdefs.asm"
	.area _CODE

_bdosgetkey::
	push de
	push bc
	push ix
	push iy
	ld c,#CMD_YIELD
	call BDOS
	rst 0x08
	cp #key_esc
	jp z,exit
	cp #key_redraw
	call z,scrredraw
	pop iy
	pop ix
	pop bc
	pop de
	ret
    