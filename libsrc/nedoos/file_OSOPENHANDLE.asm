	.module OSOPENHANDLE
	.globl errno
	.include "sysdefs.asm"
	.area _CODE
	
_OS_GETFILINFO::
	ex de, hl
	push bc
	ld l,c
	ld h,b
	ld c,#CMD_GETFILINFO	;de=filename, hl=buf[FILINFO_sz] to get FILINFO
	jr label1
_OS_SEEKHANDLE::
	push bc
    ld b,h
	push ix
	ld	ix,#0
	add	ix,sp
	ld l,4(ix)
	ld h,5(ix)
	ld e,6(ix)
	ld d,7(ix)
	pop ix
	ld c,#CMD_SEEKHANDLE	;b=file handle, dehl=offset [signed, a=method:0=begin,1=cur,2=end TODO]
	jr label1
_OS_OPENHANDLE::
	ex de, hl
	push bc
	push ix
	ld	ix,#0
	add	ix,sp
	ld a,4(ix)
	pop ix
    ex af,af'
	ld c,#CMD_OPENHANDLE	;DE = Drive/path/file ASCIIZ string
							;[A = Open mode. b0 set => no write, b1 set => no read, b2 set => inheritable, b3..b7   -  must be clear]
							;out: B = new file handle, A=error
	jr label1
_OS_CLOSEHANDLE::
	ex de, hl
	push bc
	ld b,d
	ld c,#CMD_CLOSEHANDLE ;B = file handle, out: A=error

label1:
	push ix
	push iy	
	call BDOS
	ld (errno),a
	ld h,b
	ld l,a
	pop iy
	pop ix
	pop bc
	ret
