	.module uart_delay1k
	.include "sysdefs.asm"
	.area _CODE

_uart_delay1k::
		push de
		ld e, #0xFA
loop2:		
		NOP
		dec e
		jr nz,loop2
		pop de
		ret
