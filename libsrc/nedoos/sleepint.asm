	.module sleepint
	.area _CODE

_sleepint::	;hl=sleep numbers of int
	halt 
    dec hl
    ld a,h
    or l
    jp nz, sleepint
    ret
