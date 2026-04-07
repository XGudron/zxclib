	.module OS_SETMUSIC
	.include "sysdefs.asm"
	.area _CODE

_OS_SETMUSIC::	;DE - proc_ptr, A - unknown

    ex af,af'
	push ix
	push iy

	ld	ix,#0
	add	ix,sp
	ld a,4(ix)

	ld c,#CMD_SETMUSIC	;hl=muzaddr (0x4000..0x7fff), a=muzpg
	call BDOS
	pop iy
	pop ix
	ret
	