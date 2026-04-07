	.module OS_ACCEPT
	.include "sysdefs.asm"
	.area _CODE

	; A - SOCKET
	; Возвращаемые значения в регистрах:
	; L - SOCKET при положительном значении, при отрицательном значении  - функция завершилась с ошибкой.
	; А - errno при ошибке.

_OS_ACCEPT::
	push bc
	push de
	ld l,#0x04
    ld c,#CMD_WIZNETOPEN
	ex af,af'
	push ix
	push iy
	call BDOS
	pop iy
	pop ix
	ld h, l
	ld l, a
	pop de
	pop bc
	ex de, hl
	ret
