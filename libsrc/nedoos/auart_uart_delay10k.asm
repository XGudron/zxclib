	.module uart_delay10k
	.include "sysdefs.asm"
	.area _CODE

_uart_delay10k::
		di
		push de
		ld e, #0xFA
loop2:		
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP
		NOP		
		dec e
		jr nz,loop2
		pop de
		ei
		ret
