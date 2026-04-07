	.module uart_init
	.include "sysdefs.asm"
	.area _CODE

_uart_init::	;a=divisor
		di
		push bc
		push af
		ld	bc,#0x55FE		;адрес 8952
		in	a,(c)			;Переход в режим команды
		ld	b,#0xC3			;команда - установить скорость порта
		in	a,(c)			;выполнить команду
		pop af
		ld	b,a				;параметр - установить скорость порта 19200(6) 38400(3) 115200(1) 57600(2) 9600(12) 14400(8)
		in	a,(c)			;становить параметр
		pop bc
		ei
		ret
