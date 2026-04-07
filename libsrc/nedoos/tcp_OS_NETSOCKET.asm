	.module OS_NETSOCKET
	.include "sysdefs.asm"
	.area _CODE

_OS_NETSOCKET::
	ex de, hl
	;D - AF_INET
	;E - (0x01 tcp/ip, 0x02 icmp, 0x03 udp/ip
	;------
	;L - SOCKET
	;A - ErrNo
	push bc
	ld l,#0x01
	ld c, #CMD_WIZNETOPEN
	ex af,af'
	push ix
	push iy
	call BDOS
	pop iy
	pop ix
	pop bc
	ld h, l
	ld l, a
	ex de, hl
	ret
