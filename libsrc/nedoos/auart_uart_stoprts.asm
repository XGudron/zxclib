	.module uart_stoprts
	.include "sysdefs.asm"
	.area _CODE

_uart_stoprts::
		push bc
		ld	bc,#0x55FE		;адрес 8952
		in	a,(c)			;Переход в режим команды
		ld	b,#0x43			;команда - установить статус
		in	a,(c)
		ld	b,#0x00			;Параметры - установить RTS (STOP)
		in	a,(c)
		pop bc
		ret
