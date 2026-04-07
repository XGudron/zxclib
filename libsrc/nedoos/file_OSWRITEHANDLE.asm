	.module OSWRITEHANDLE
	.globl errno
	.include "sysdefs.asm"
	.area _CODE

_OS_SETSYSDRV::
	ld c,#CMD_SETSYSDRV			;out: a!=0 => not mounted, l=number of drives
	jr label3
_OS_GETFILESIZE::
	ex de, hl
	ld c,#CMD_GETFILESIZE		;b=handle, out: dehl=file size
	ld b,d
	jr label3
_OS_GETPATH::
	ex de, hl
	ld c,#CMD_GETPATH			;DE = Pointer to MAXPATH_sz byte buffer ;out: DE = Filled in with whole path string (WITH DRIVE! Finished by slash only if root dir), HL = Pointer to start of last item
	jr label3
_OS_READHANDLE::
_OS_READHANDLEMEM::
	ex de, hl
	ld b, h
	ld c, l
	push ix
	ld	ix,#0
	add	ix,sp
	ld h,5(ix)
	ld l,4(ix)
	pop ix
	ld c,#CMD_READHANDLE		;B = file handle, DE = Buffer address, HL = Number of bytes to read, out: HL = Number of bytes actually read, A=error(=0)
	jr label3
_OS_WRITEHANDLE::
	ex de, hl
	ld b, h
	ld c, l
	push ix
	ld	ix,#0
	add	ix,sp
	ld h,5(ix)
	ld l,4(ix)
	pop ix
	ld c,#CMD_WRITEHANDLE		;B = file handle, DE = Buffer address, HL = Number of bytes to write, out: HL = Number of bytes actually written, A=error(=0)

label3:
	pop af
	pop hl
	push hl
	push af
	push ix
	push iy	
	call BDOS
	ld (errno),a
	ld b,d
	ld c,e
	pop iy
	pop ix
	ret
