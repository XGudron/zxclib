	.module OS_STDIO
	.globl initstdio, receivekey, sendchar, sendchars
	.globl yieldgetkeyloop
	.include "sysdefs.asm"
	.area _CODE
	.include "stdio.asm"
