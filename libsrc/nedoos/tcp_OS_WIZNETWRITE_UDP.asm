	.module OS_WIZNETWRITE_UDP
	.include "sysdefs.asm"
	.area _CODE

_OS_WIZNETWRITE_UDP::
	; HL - readstructure DE - sockaddr_in
	ld b, d
	ld c, e
	; DE - readstructure BC - sockaddr_in
	;ex de,hl			;HL - sockaddr_in, DE - garbage
	ld a, (hl) 			;A  - socket
	inc hl
	ld e,(hl)
	inc hl
	ld d,(hl)
	inc hl
	push de
	ld (store_ix),ix
	pop ix				;IX - BufAdr
	ld e, (hl) 			;E - Bufsize L
	inc hl
	ld d, (hl) 			;D  - Bufsize H
	ex de,hl			;HL - Bufsize
	ld d,b				;DE - sockaddr_in
	ld e,c				
	ex af,af'
	ld c, #CMD_WIZNETWRITE
	push ix
	push iy
	call BDOS
	pop iy
	pop ix
	bit 7, h
	jp z, writeok 		;noerror just return
	ld l, a
writeok:
writenot:
	ld ix,(store_ix)
	ex de,hl
	ret
store_ix:
	.db 0,0,0
