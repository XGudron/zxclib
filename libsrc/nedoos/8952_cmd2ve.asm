	.module cmd2ve
	.include "sysdefs.asm"
	.area _CODE
	
_cmd2ve::	;a=command	 возвращаем результат в A
		di
		push bc
		push af
		ld	bc,#0x55FE		;адрес 8952
		in	a,(c)			;Переход в режим команды
		pop af
		ld	b,a				;команда из A переноcим в B
		in	a,(c)			;выполнить команду
		pop bc
		ei
		ret
	