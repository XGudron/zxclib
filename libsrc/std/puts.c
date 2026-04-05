extern int putchar(int c);

int puts(char *str) {
	const char *ptr = str;
	while (*ptr) {
		char chr = *(ptr++);
		if (chr == 0x0A) {
			continue;
		}
		putchar(chr);
	}

	return 1;
}
