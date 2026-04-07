	.module uart_flashrts
	.include "sysdefs.asm"
	.area _CODE

_uart_flashrts::
		push bc
		ld	bc,#0x55FE		;адрес 8952
		in	a,(c)			;Переход в режим команды
		ld	b,#0x43			;команда - установить статус
		IN	a,(c)
		ld	b,#0x03			;Параметры - убрать RTS (START)
		in	a, (c)
		pop bc
		push bc
		ld	bc,#0x55FE		;адрес 8952
		in	a,(c)			;Переход в режим команды
		ld	b,#0x43			;команда - установить статус
		in	a,(c)
		ld	b,#0x00			;Параметры - установить RTS (STOP)
		in	a,(c)
		pop bc
		ret
