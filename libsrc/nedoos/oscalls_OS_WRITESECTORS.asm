	.module OS_WRITESECTORS	;de= pointer to diskOp structure
	.include "sysdefs.asm"
	.area _CODE
	.allow_undocumented

OS_WRITESECTORS::
	push bc
	push de
	push ix
	push iy

	;ex de,hl
	ld b,(hl) 	;drive
	inc l
	ld e,(hl) 	;buffer L
	inc l
	ld d,(hl) 	;buffer H
	inc l
	push de
	ld e,(hl) 	;sector L
	inc l
	ld d,(hl) 	;sector H
	inc l
	ld  a,(hl)	;sector X
	ld  ixl,a
	inc l
	ld  a,(hl)	;sector I
	ld  ixh,a
	inc l
	ld  a,(hl)	;count
	pop hl
	ex de,hl
	ld c,#CMD_WRITESECTORS
	ex af,af' ;'
    call BDOS ;c=CMD
	pop iy
	pop ix
	pop de
	pop bc
	ex de,hl
	ret		;HL	
