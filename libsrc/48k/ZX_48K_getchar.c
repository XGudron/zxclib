#include "zx_48k.h"

int ZX_48K_getchar(void)
{
    __asm
        ; Открываем канал ввода K-CHANNEL (канал 0)
        ld   a, #0        ; канал 0 - K-CHANNEL
        call 0x1601      ; CHAN-OPEN
        
        ; Читаем символ из канала
        call 0x15DE      ; GET-CHAR - ROM подпрограмма чтения символа из канала
        ld   e, a        ; ASCII код в E
        ret
    __endasm;


	return 0;
}
