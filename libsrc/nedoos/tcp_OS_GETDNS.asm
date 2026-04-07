	.module OS_GETDNS
	.include "sysdefs.asm"
	.area _CODE

_OS_GETDNS::
	ld l,#0x08
	push ix
	push iy	
	ld a,c
	ex af,af'
	ld c,#CMD_WIZNETOPEN ;A=SOCKET, L=subfunction (see sys_h.asm)
	call BDOS
	ld a,l
	pop iy
	pop ix
	ret
