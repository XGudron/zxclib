	.module OS_NEWAPP
	.include "sysdefs.asm"
	.area _CODE

_OS_NEWAPP::
	ex de, hl
	push bc
	ld (strPtr), de
	push ix
	push iy
	ld c,#CMD_NEWAPP				;out: b=id, a=error, dehl=newapp pages in 0000,4000,8000,c000 ;MAKE NEW DISABLED APP
	call BDOS
	pop iy
	pop ix
	ld c,a
	push hl
	ld hl,(strPtr)
	ld (hl),d
	inc hl
	ld (hl),e
	pop hl
	ex de,hl
	ld hl,(strPtr)
	inc hl
	inc hl
	ld (hl),d
	inc hl
	ld (hl),e
	inc hl
	ld (hl),b
	inc hl
	ld (hl),c
	pop bc
	ex de, hl
	ret
strPtr:
	.dw 0000
