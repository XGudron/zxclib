	.module viewScreen6912
	.include "sysdefs.asm"
	.area _CODE

	.macro YIELD
	push bc
	ld c, #CMD_YIELD
	push ix
	push iy
	call  BDOS
	pop iy
	pop ix
	pop bc
	.endm

_viewScreen6912::
; unsigned int viewScreen6912(unsigned char pause, unsigned int bufAdr);
; HL = buffer adress DE = time in ints out A = key
	xor a
	ld (key), a
	push bc
	push de ; not for exit 
	push hl ; not for exit 

	ld c, #CMD_GETMAINPAGES	;d,e,h,l=pages in 0000,4000,8000,c000, c=flags, b=id
	push ix
	push iy
	call BDOS
	pop iy
	pop ix	

	ld (pg4),de
	ld (pgC),hl
display:
	ld e, #0x83
	ld c, #CMD_SETGFX
	push ix
	push iy
	halt
	call  BDOS
	pop iy
	pop ix
	
	ld a,(user_scr0_high)
	
	push ix
	push iy
	rst 0x28		;SETPGC000
	pop iy
	pop ix
	
    pop hl			; DE - buffer adress
	ld de, #0xC000
	ld bc, #6912
	ldir
    
	xor a
	out (0xfe), a	;border 0

	pop bc			; tics
	ld a, b
    or c
    jp nz, slideshow	;	tics != 0
	
inkey:
	
	YIELD
	
	push ix
	push iy
	rst 0x08		;OS_GETKEY
	pop iy
	pop ix
	halt
	halt
	jp nz, inkey
	ld a,c
	or a
	jp z, inkey

exit3:
	ld (key), a
	ld e, #0x86
	ld c, #CMD_SETGFX
	push ix
	push iy
	;halt
	call BDOS
	pop iy
	pop ix
	ld a, (pgC)
	push ix
	push iy
	rst 0x28	;SETPGC000
	pop iy
	pop ix
	pop bc
	ld a, (key)
	ret

slideshow: ;BC ints
	YIELD
	dec bc
	ld (waiting),bc

	push ix
	push iy
	rst 0x08
	pop iy
	pop ix	
	ld a,c
	or a
    jp nz, exit3	
	halt
	ld bc,(waiting)
	ld a, b
    or c
    jp nz, slideshow
	ld a, #32
	jp exit3	
pg4:		.db 0
pg0:		.db 0
pgC:		.db 0
pg8:		.db 0
waiting: .dw 0
key:		.db 0
