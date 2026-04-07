	.module OS_LISTEN
	.include "sysdefs.asm"
	.area _CODE

	; A - SOCKET
	; Возвращаемые значения в регистрах:
	; L - При отрицательном значении - функция завершилась с ошибкой.
	; А - errno при ошибке.

_OS_LISTEN::
	push bc
	push de
	ld l,#0x06
    ld c,#CMD_WIZNETOPEN
	ex af,af'
	push ix
	push iy
	call BDOS
	pop iy
	pop ix
	pop de
	pop bc
	ld h, l
	ld l, a
	ex de, hl
	ret
