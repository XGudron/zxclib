	.module uart_queue
	.include "sysdefs.asm"
	.area _CODE

_uart_queue::					;out a = queue
		push bc
		ld	bc,#0x55FE		;адрес 8952
		in	a,(c)			;Переход в режим команды
		ld	b,#0xC2			;команда - чтение счетчика буфера приема
		in	a,(c)			;Получили число байт в буфере
		pop bc
		ret
	