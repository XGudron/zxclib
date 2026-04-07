.optsdcc -mz80 sdcccall(1)
.globl	_main

.area _HEADER (ABS)
	.org 0x0100

init:
	;; Set stack pointer directly
	ld	sp, #0xBFFF

	;; Initialise global variables. Skip if __sdcc_external_startup returned
	;; non-zero value. Note: calling convention version 1 only.
	call	___sdcc_external_startup
	or	a, a
	call	Z, gsinit

	call _main
	jp exit

	;; Ordering of segments for the linker.
	.area	_HOME
	.area	_CODE

_putchar::
	call _ttyputchar
	ret

_puts::
	call _ttyputs
	ret

_gets::
	call _ttygets
	ret

	.area	_INITIALIZER
	.area   _GSINIT
	.area   _GSFINAL

	.area	_DATA
	.area	_INITIALIZED
	.area	_BSEG
	.area   _BSS

	.area   _GSINIT
gsinit::

	; Default-initialized global variables.
        ld      bc, #l__DATA
        ld      a, b
        or      a, c
        jr      Z, zeroed_data
        ld      hl, #s__DATA
        ld      (hl), #0x00
        dec     bc
        ld      a, b
        or      a, c
        jr      Z, zeroed_data
        ld      e, l
        ld      d, h
        inc     de
        ldir
zeroed_data:

	; Explicitly initialized global variables.
	ld	bc, #l__INITIALIZER
	ld	a, b
	or	a, c
	jr	Z, gsinit_next
	ld	de, #s__INITIALIZED
	ld	hl, #s__INITIALIZER
	ldir

gsinit_next:

	.area   _GSFINAL
	ret
