	.module TTYGETS
	.globl bs_loop,yieldgetkeyloop,exit,sendchars
	.globl sendchar
	.include "sysdefs.asm"
	.area _CODE

_ttygets::
	ex de, hl
	xor a
	ld (de),a
	ld (str_begin + 1),de
	push bc
	push ix
	push iy
main_loop:
	push de
main_loop1:
	call yieldgetkeyloop
	or a
	jr z,main_loop1
	pop de
	cp #key_esc
	jp z,exit
	cp #key_enter
	jr nz,no_enter
	ld de,#str_rn
	ld hl,#2
	call sendchars
str_begin:
	ld hl,#0
	pop iy
	pop ix
	pop bc
	ex de, hl
	ret
str_rn:
	.ascii '\r\n'
no_enter:
	cp #key_left
	jr nz,no_left
	ld hl,(str_begin + 1)
	sbc hl,de
	jr z,main_loop
	dec de
left_1:
	push de
	ld hl,#3
	ld de,#csi_left
	call sendchars
	jr main_loop1
csi_left:
	.db 0x1b,'[','D'
no_left:
	cp #key_right
	jr nz,no_right
	ld a,(de)
	or a
	jr z,main_loop
right_1:
	inc de
	push de
	ld hl,#3
	ld de,#csi_right
	call sendchars
	jr main_loop1
csi_right:
	.db 0x1b,'[','C'
no_right:
	cp #extH
	jr nz,no_backspace
	ld hl,(str_begin + 1)
	sbc hl,de
	jr z,main_loop
	push de
	ld hl,#3
	ld de,#csi_left
	call sendchars
	pop de
	ld b,d
	ld c,e
	dec de
	ld h,d
	ld l,e
bs_loop:
	ld a,(bc)
	ld (hl),a
	inc bc
	inc hl
	or a
	jr nz,bs_loop
	sbc hl,de
	call puts_w_restore
	jp main_loop
no_backspace:
	cp #0xfc
	jr nz,no_del
	ld b,d
	ld c,e
	ld h,d
	ld l,e
	inc bc
del_loop:
	ld a,(bc)
	ld (hl),a
	inc bc
	inc hl
	or a
	jr nz,del_loop
	sbc hl,de
	call puts_w_restore
	jp main_loop
no_del:
	ld (store_ch + 1),a
	ld h,d
	ld l,e
	ld a,(hl)
sh_right:
	inc hl
	ld b,(hl)
	ld (hl),a
	or a
	ld a,b
	jr nz,sh_right
store_ch:
	ld a,#0
	ld (de),a
	sbc hl,de
	call puts_w_restore
	jr right_1
	
puts_w_restore:
	push de
	ld (pw_size + 1),hl
	ld hl,#3
	ld de,#csi_save_cursor
	call sendchars
	pop de
	push de
pw_size:
	ld hl,#0
	call sendchars
	ld hl,#4
	ld de,#csi_rest_cursor
	call sendchars
	pop de
	ret
csi_save_cursor:
	.db 0x1b,'[','s'
csi_rest_cursor:
	.db ' ',0x1b,'[','u'
