	.module MAIN_ARGS
	.area _CODE

_main_args::
	ld hl,#args
	ld de,#0x0080
get_cmd_args_l2:
	ld (hl),e
	inc hl
	ld (hl),d
	inc hl
	dec de
get_cmd_args_l:
	inc de
	ld a,(de)
	or a
	jr z,get_cmd_args_end
	cp #' '
	jr nz,get_cmd_args_l
	xor a
	ld (de),a
skipspaces:
	inc de
	ld a,(de)
	or a
	jr z,get_cmd_args_end
	cp #' '
	jr nz,get_cmd_args_l2
	jr skipspaces
get_cmd_args_end:
	ld bc,#args
	sbc hl,bc
	ex de,hl
	srl e
	ret
	.area _NO_INIT
args:
	.ds 32
