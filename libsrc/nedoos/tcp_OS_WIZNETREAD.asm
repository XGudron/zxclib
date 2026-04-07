	.module OS_WIZNETREAD
	.include "sysdefs.asm"
	.area _CODE

	;if TCP: A=SOCKET, de=buffer_ptr, 		HL=sizeof(buffer)
	;else:	 A=SOCKET, de=sockaddr_in ptr,	HL=sizeof(buffer), IX=buffer_ptr,
	;out: HL=count if HL < 0 then A=error 
_OS_WIZNETREAD::
	push bc
	;ex de,hl
	ld a, (hl) 	;socket
	inc hl
	ld e, (hl) 	;buffer L
	inc hl
	ld d, (hl) 	;buffer H
	inc hl
	ld c, (hl) 	;size L
	inc hl
	ld b, (hl) 	;size H
	ld l, c
	ld h, b
	ld c, #CMD_WIZNETREAD
	push ix
	push iy
	ex af,af'
	call BDOS
	pop iy
	pop ix
	bit 7, h
	jp z, readok 	;noerror just return
	ld l, a
	jp readnot
readok:
readnot:
	pop bc
	ex de,hl
	ret
