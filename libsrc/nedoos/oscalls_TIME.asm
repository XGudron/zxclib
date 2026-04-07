
    .module TIME
	.include "sysdefs.asm"
	.area _CODE

_time::
        push ix
        push iy
    ld c,#CMD_GETTIMER ;out: dehl=timer
	call BDOS
        ld b,d
        ld c,e
        pop iy
        pop ix
        ret ;return bchl
