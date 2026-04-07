	.module uart_write
	.include "sysdefs.asm"
	.area _CODE

_uart_write::	;a=byte to send
		di
		push bc
		push af
readytx:
		ld	bc,#0x55FE		;адрес 8952
		in	a,(c)			;Переход в режим команды
		ld	b,#0x42			;команда - прочесть статус
		in	a,(c)
		bit	6,a				;Параметры - TX 
		jp z,readytx		; вернуться если байта нет
		ld	bc,#0x55FE		;адрес 8952
		in	a,(c)			;Переход в режим команды
		ld	b,#0x03			;запись
		in	a,(c)
		pop af
		ld	b,a				;БАЙТ для пересылки
		in	a,(c)			; ->
		pop bc
		ei		
		ret
