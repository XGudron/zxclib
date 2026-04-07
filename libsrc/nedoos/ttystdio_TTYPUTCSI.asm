	.module TTY_PUTCSI
	.globl sendchars,sendchar
	.area _CODE

putcsi2:
	ld hl,#4
	jr .+3
_putcsi::
	ld hl,#3
	push bc
	push ix
	push iy
	ld (csi+2),a
	ld de,#csi
	call sendchars
	pop iy
	pop ix
	pop bc
	ld de,#0x0000
	ret
csi: 
	.db 0x1b,'[',0,0,0,0
