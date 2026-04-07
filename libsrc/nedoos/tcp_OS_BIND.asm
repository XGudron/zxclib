	.module OS_BIND
	.include "sysdefs.asm"
	.area _CODE

	;  A - SOCKET
	;  DE - указатель на структуру sockaddr_in содержащую номер исходящего порта.
	;   (остальные поля структуры не используются, но обязаны присутствовать)
	; Возвращаемые значения в регистрах:
	;  L - При отрицательном значении - функция завершилась с ошибкой.
	;  А - errno при ошибке

_OS_BIND::
	push bc
	ld d, b
	ld e, c
	ld l,#0x05
    ld c,#CMD_WIZNETOPEN
	push ix
	push iy
	ex af,af'
	call BDOS
	pop iy
	pop ix
	ld h, l
	ld l, a
	pop bc
	ex de, hl
	ret
