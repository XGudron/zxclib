	.module OS_NETCONNECT
	.include "sysdefs.asm"
	.area _CODE

_OS_NETCONNECT::
	;A  - Socket
	;DE - Pointer to adrstruct
	;------
	;L - <0 err
	;H - ErrNo
	;CMD_WIZNETOPEN=0xdb ;A=SOCKET, L=subfunction (see sys_h.asm)
	push bc
	ld d, b
	ld e, c
	ex af,af'
	ld c, #CMD_WIZNETOPEN
	ld l,#0x03
	push ix
	push iy
	call BDOS
	pop iy
	pop ix
	ld h, l
	LD l, a
	pop bc
	ex de,hl
	ret
