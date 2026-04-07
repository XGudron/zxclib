	.module viewScreen6912NoKeyGraph
	.include "sysdefs.asm"
	.area _CODE

_viewScreen6912NoKeyGraph::
	ld a, d
	ld (waiting), a		; ints
	ld (bufAdr), hl		; bufadr
	ld a, e
	ld (border), a		; border

	ld e, a
    push bc
	push hl
	push ix
	push iy
    ld c,#CMD_SETBORDER ;e=0..15
	call BDOS
	pop iy
	pop ix
	pop hl
	pop bc


	push hl

	ld c, #CMD_GETMAINPAGES	;d,e,h,l=pages in 0000,4000,8000,c000, c=flags, b=id
	push ix
	push iy
	call BDOS
	pop iy
	pop ix	

	ld (pg4),de
	ld (pgC),hl
display2:
	ld a, (curScr)
	or a
	ld a,(user_scr1_high)
	jp z, fillScr
	ld a,(user_scr0_high)
fillScr:
	push ix
	push iy
	rst 0x28		;SETPGC000
	pop iy
	pop ix

    ld hl, (bufAdr)
	ld de, #0xC000
	ld bc, #6912
	ldir

	ld a, (curScr)
	xor #1
	ld (curScr), a

changeScr:
	ld a, (curScr)
	ld e,a
    push bc
	push hl
	push ix
	push iy
	ld c,#CMD_SETSCREEN
	call BDOS
	pop iy
	pop ix
	pop hl
	pop bc


slideshow_: ;BC ints
	ld a, (waiting)
	ld c, a
slideshow2:
	halt
	dec c
    jp nz, slideshow2
exit4:
	ld a, (pgC)
	push ix
	push iy
	rst 0x28	;SETPGC000
	pop iy
	pop ix
	pop de
	ret




pg4:		.db 0
pg0:		.db 0
pgC:		.db 0
pg8:		.db 0
waiting: .dw 0
bufAdr:  .dw 0
border:	.dw 0
curScr:  .db 0
