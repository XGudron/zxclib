	.module OS_NETSHUTDOWN
	.include "sysdefs.asm"
	.area _CODE

	; A - SOCKET
	; E - Варианты закрытия, 0 - закрыть немедленно, 1 - закрыть только если буфер отправки пуст.
	; Возвращаемые значения в регистрах:
	; L - SOCKET при положительном значении, при отрицательном значении  - функция завершилась с ошибкой.
	; А - errno при ошибке.

_OS_NETSHUTDOWN::
	push bc
	push de
	ld e, l
	ld l,#0x02
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
