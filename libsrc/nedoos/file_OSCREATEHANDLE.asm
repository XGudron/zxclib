	.module OSCREATEHANDLE
	.globl errno
	.include "sysdefs.asm"
	.area _CODE

_OS_CREATEHANDLE::
	ex de, hl
	push ix
	push iy
	ld	ix,#0
	add	ix,sp

	ld a,4(ix)
	and #0x80
	ld b,a
	ld a,4(ix)
	and #0x7f
    ex af,af'
	ld c,#CMD_CREATEHANDLE	;DE = Drive/path/file ASCIIZ string
                        	;[A = Open mode. b0 set => no write, b1 set => no read, b2 set => inheritable, b3..b7   -  must be clear]
                        	;[B = b0..b6 = Required attributes, b7 = Create new flag]
                        	;out: B = new file handle, A=error
	call BDOS
	ld (errno),a
	ld h,b
	ld l,a
	pop iy
	pop ix
	ret
	