	.module OSDIRCALLS
	.globl errno
	.include "sysdefs.asm"
	.area _CODE

_OS_READDIR:: 
	ex de, hl
	push bc
	ld c,#CMD_READDIR	;de=buf for FILINFO (if no LNAME, use FNAME), 0x00 in FILINFO_FNAME = end dir
	jr label2
_OS_OPENDIR:: 
	ex de, hl
	push bc
	ld c,#CMD_OPENDIR	;de=path
	jr label2
_OS_DELETE::
	ex de, hl
	push bc
	ld c,#CMD_DELETE	;DE = Drive/path/file ASCIIZ string, out: A = Error
	jr label2
_OS_MKDIR::
	ex de, hl
	push bc
	ld c,#CMD_MKDIR		;DE = Pointer to ASCIIZ string, out: a
	jr label2
_OS_CHDIR::
	ex de, hl
	push bc
	ld c,#CMD_CHDIR		;DE = Pointer to ASCIIZ string. Out A=error
	jr label2
_OS_CHDRV::
	ld e, a
	push bc
	ld c,#CMD_SETDRV	;e=drive ;out: a!=0 => not mounted, [l=number of drives]

label2:
	push ix
	push iy	
	call BDOS
	ld (errno),a
	pop iy
	pop ix
	pop bc
	ret
