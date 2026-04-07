	.module uart_read
	.include "sysdefs.asm"
	.area _CODE

_uart_read::					;out a = byte
		di
		push bc
read2:
		ld	bc,#0x55FE		;адрес 8952
		in	a,(c)			;Переход в режим команды
		ld	b,#0xC2			;команда - чтение счетчика буфера приема
		in	a,(c)			;Получили число байт в буфере
		or a
		jp nz,togetb		; В буфере есть байт
		jp read2			; А теперь есть?

togetb:		
		ld	bc,#0x55FE		;адрес 8952
		in	a,(c)			;Переход в режим команды
		ld	b,#0x02			;команда - чтение 
		in	a,(c)			;Получаем байт в А
		pop bc
		ei
		ret	
