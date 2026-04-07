	.module OS_INITSTDIO
	.globl initstdio
	.area _CODE
_os_initstdio::
	push hl
	push bc
	push de
	push ix
	push iy
	call initstdio
	pop iy
	pop ix
	pop de
	pop bc
	pop hl
	ret
