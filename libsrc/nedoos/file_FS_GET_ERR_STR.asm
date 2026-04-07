	.module FS_GET_ERR_STR
	.globl errno
	.include "sysdefs.asm"
	.area _CODE

_fs_get_err_str::
	LD	HL,(errno)
	LD	H,#0
	ADD	HL,HL
	LD	BC,#fs_errs
	ADD	HL,BC
	LD	a,(HL)
	INC	HL
	LD	d,(HL)
    ld e,a
	ret
    
	.area _CONST

fs_errs:
	.dw	err0010
	.dw	err0011
	.dw	err0012
	.dw	err0013
	.dw	err0014
	.dw	err0015
	.dw	err0016
	.dw	err0017
	.dw	err0018
	.dw	err0019
	.dw	err0020
	.dw	err0021
	.dw	err0022
	.dw	err0023
	.dw	err0028
	.dw	err0028
	.dw	err0028
	.dw	err0028
	.dw	err0028
	.dw	err0029
	
err0010:
	.ascii	'Succeeded'
	.db	0
err0011:
	.ascii	'A hard error occured in the low level disk I/O layer'
	.db	0
err0012:
	.ascii	'Assertion failed'
	.db	0
err0013:
	.ascii	'The physical drive cannot work'
	.db	0
err0014:
	.ascii	'Could not find the file'
	.db	0
err0015:
	.ascii	'Could not find the path'
	.db	0
err0016:
	.ascii	'The path name format is invalid'
	.db	0
err0017:
	.ascii	'Acces denied due to prohibited access or directory full'
	.db	0
err0018:
	.ascii	'Acces denied due to prohibited access'
	.db	0
err0019:
	.ascii	'The file/directory object is invalid'
	.db	0
err0020:
	.ascii	'The physical drive is write protected'
	.db	0
err0021:
	.ascii	'The logical drive number is invalid'
	.db	0
err0022:
	.ascii	'The volume has no work area'
	.db	0
err0023:
	.ascii	'There is no valid FAT volume on the physical drive'
	.db	0
err0028:
	.ascii	'file error'
	.db	0
err0029:
	.ascii	'Without MBR'
	.db	0
