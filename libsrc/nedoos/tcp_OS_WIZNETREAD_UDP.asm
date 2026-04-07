	.module OS_WIZNETREAD_UDP
	.include "sysdefs.asm"
	.area _CODE

_OS_WIZNETREAD_UDP::
	; HL - readstructure DE - sockaddr_in
	ld b, d
	ld c, e
	; DE - readstructure BC - sockaddr_in
	;ex de,hl			;HL - readstructure, DE - garbage
	ld a, (hl) 			;A  - socket
	inc hl
	ld e,(hl)
	inc hl
	ld d,(hl)
	inc hl
	push de
	ld (store_ix),ix
	pop ix
	ld e, (hl) 			;E - Bufsize L
	inc hl
	ld d, (hl) 			;D  - Bufsize H
	ex de,hl			;HL - Bufsize
	ld d,b				;DE - sockaddr_in
	ld e,c				;
	ex af,af'
	ld c, #CMD_WIZNETREAD
	push ix
	push iy
	call BDOS
	pop iy
	pop ix
	bit 7, h
	jp z, readok 	;noerror just return
	ld l, a
readok:
readnot:
	ld ix,(store_ix)
	ex de,hl
	ret
store_ix:
	.db 0,0,0
