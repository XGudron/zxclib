        .module CLEARC000FAST
        .include "sysdefs.asm"
        .area _CODE

_CLEARC000FAST::	
        push hl
		push de
		push bc
		LD HL,#0xc000 + 6912		; конец картинки
        LD DE,#0x0000			; заполнение
        LD B,#0x36				; количество циклов заполнения
;       CALL fill_hl_de_b
;       RET
fill_hl_de_b:
        LD (sp_back),SP
        LD SP,HL
l1b:
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        PUSH DE
        DJNZ l1b
	.db 0x31		;ld sp, nn
sp_back:
        .dw 0x0000
		pop bc
		pop de
		pop hl
        RET
