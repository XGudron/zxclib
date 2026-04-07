	.module send2ve
	.include "sysdefs.asm"
	.area _CODE

_send2ve::	;a=command l=data
		di
		push af
		ld d,c
		ld	bc,#0x55FE		;адрес 8952
		in	a,(c)			;Переход в режим команды
		pop af
		ld	b,a				;команда 
		IN	a,(c)
		ld	b,l				;Параметр
		in	a,(c)
		ei
		ret
