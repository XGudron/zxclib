    .module OS_GETTIME ; unsigned long OS_GETTIME (struct diskOp *); //out: ix=date, hl=time
	.include "sysdefs.asm"
	.area _CODE

_OS_GETTIME::
    push ix
    push iy
    ld c,#CMD_GETTIME ;out: ix=date, hl=time
	call BDOS
	di
	push ix
	pop de
	ei
  	pop iy
    pop ix
    ret ;return bchl
