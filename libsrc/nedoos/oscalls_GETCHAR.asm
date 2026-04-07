	.module GETCHAR
	.area _CODE

_getchar::
	call _ttygetkey ; use _ttygetkey_ne for skip ESC exit
	or a
	jr z,_getchar
	ret	
	