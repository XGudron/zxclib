#include "zxclib.h"
#include "nedoos.h"

#include <stdint.h>
#include <stdio.h>

char tmp_str[32] = "";

void main(void) {
	os_initstdio();
	OS_SETXY(10, 10);
	printf("Hello from NedoOS !\r\n");
	puts("puts test\r\n");

	/*while(1) {
		putchar(getchar());
	}*/

	/*while(1) {
		putchar(getchar());
	}*/

	/*while(1) {
		char chr = ttygetkey_ne();
		if (chr == 0) {
			continue;
		}
		putchar(chr);
	}*/

	memset(tmp_str, 0x00, sizeof(tmp_str));
	puts(gets(tmp_str));

	puts("Demo end !\r\n");
	while(1) {}
}
