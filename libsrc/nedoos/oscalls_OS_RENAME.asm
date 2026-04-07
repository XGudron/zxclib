	.module OS_RENAME
	.include "sysdefs.asm"
	.area _CODE

_OS_RENAME::
	ex de, hl
	push ix
	push iy
	ld c,#CMD_RENAME ;DE = Drive/path/file ASCIIZ string, HL = New filename ASCIIZ string (NOT MSXDOS compatible! with Drive/path!) ;RENAME OR MOVE FILE
	call BDOS
	pop iy
	pop ix
	ex de, hl
	ret
