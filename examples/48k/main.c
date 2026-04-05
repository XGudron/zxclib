#include "zxclib.h"
#include <stdint.h>
#include <stdio.h>

uint8_t color_counter;
char initialized_str[] = "Hello, ";
const char constant_str[] = "Z80 world!\r";
static uint16_t interrupt_counter = 0;
char key1_pressed, key2_pressed;

#define DEMO_DATA_SIZE 5
uint8_t demo_data[DEMO_DATA_SIZE] = {0x01, 0x02, 0x03, 0x04, 0x05};

void my_interrupt_handler(void) __interrupt {
	interrupt_counter++;

	__asm
		RST 56; ROM interrupt process
	__endasm;
}

void main(void) {
	ZX_48K_open_channel(ZX_CHANNEL_TOP);
	ZX_48K_clear_screen();

	puts(initialized_str);
	ZX_48K_set_ink(ZX_COLOR_GREEN);
	ZX_48K_set_paper(ZX_COLOR_RED);
	puts(constant_str);
	ZX_48K_set_bright(ZX_BRIGHT_HIGH);
	ZX_48K_set_flash(ZX_FLASH_ON);
	printf("Test printf %d\r", 10);
	ZX_48K_recover_IY();

	ZX_48K_beeper(500, 200);
	ZX_48K_beeper(200, 200);
	ZX_48K_beeper(100, 200);

	ZX_48K_set_attributes(ZX_COLOR_BLACK, ZX_COLOR_WHITE, ZX_BRIGHT_NORMAL, ZX_FLASH_OFF);
	ZX_48K_plot(10, 50);
	ZX_48K_plot(20, 50);
	ZX_48K_draw_line_step(10, 10, -1, 2);
	ZX_48K_draw_line(30, 50, 25, 40);
	ZX_48K_draw_line(30, 50, 40, 60);

	puts("Press any keys to test...\r");
	for (uint8_t i = 0; i < 5; i++) {
		char tmp = getchar();
		putchar(tmp);
	}

	ZX_48K_save_bytes(demo_data, DEMO_DATA_SIZE, 255);

	ZX_48K_clear_lines(20);
	ZX_48K_scroll_up();
	ZX_48K_open_channel(ZX_CHANNEL_TOP);

	ZX_set_im2_handler(my_interrupt_handler);

	while (1) {
		for (color_counter = 0; color_counter < 8; color_counter++) {

			ZX_48K_set_cursor_position(10, 5);
			printf("%d", interrupt_counter);
			ZX_48K_recover_IY();

			uint16_t keys_pressed = ZX_48K_keyscan();
			key1_pressed = keys_pressed & 0xFF;
			key2_pressed = (keys_pressed >> 8) & 0xFF;
			if (key1_pressed != 0xFF) {
				ZX_48K_clear_screen();
				printf("Keys pressed: %d %d\r", key1_pressed, key2_pressed);
				ZX_48K_recover_IY();
			}

			ZX_set_border(color_counter);

			for (uint32_t delay = 0; delay < 20000; delay++) {
			}
		}
	}
}
