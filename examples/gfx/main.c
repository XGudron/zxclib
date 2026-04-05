#include "zxclib.h"
#include <stdint.h>
#include <stdio.h>

const uint8_t gliph[] = {
	0b01000010,
	0b01011010,
	0b01011010,
	0b00111100,
	0b00011000,
	0b00011000,
	0b00011000,
	0b00000000,
};

void main(void) {
	ZX_GFX_clear_screen();
	ZX_GFX_fill_screen(ZX_COLOR_BLUE, ZX_COLOR_YELLOW, ZX_BRIGHT_NORMAL, ZX_FLASH_OFF);
	ZX_set_border(ZX_COLOR_BLACK);

	ZX_GFX_draw_pixel(10, 10);
	ZX_GFX_clear_pixel(10, 10);
	// ZX_GFX_get_pixel(10, 10);

	ZX_GFX_draw_horizontal_line(10, 20, 10);
	ZX_GFX_draw_vertical_line(10, 10, 20);
	ZX_GFX_draw_line(10, 20, 20, 10);

	uint16_t maxWidth = ZX_SCREEN_WIDTH_PX - 1;
	uint16_t maxHeight = ZX_SCREEN_HEIGHT_PX - 1;
	ZX_GFX_draw_rectangle(0, 0, maxWidth, maxHeight);
	ZX_GFX_fill_rectangle(maxWidth - 20, maxHeight - 20, maxWidth, maxHeight);

	ZX_GFX_draw_circle(100, 100, 20);
	ZX_GFX_fill_circle(100, 100, 10);
	ZX_GFX_draw_ellipse(150, 100, 20, 10);

	ZX_GFX_draw_triangle(maxWidth - 10, 10, maxWidth - 40, 10, maxWidth - 10, 40);
	ZX_GFX_fill_triangle(maxWidth - 20, 20, maxWidth - 30, 20, maxWidth - 20, 30);

	ZX_GFX_draw_rounded_rectangle(50, 150, 100, 170, 7);
	ZX_GFX_fill_rounded_rectangle(150, 150, 200, 170, 5);

	ZX_GFX_draw_gliph(50, 100, gliph);
	// ZX_GFX_set_pixel_ink(50, 100, ZX_COLOR_RED);
	// ZX_GFX_set_pixel_paper(50, 100, ZX_COLOR_RED);
	// ZX_GFX_set_pixel_bright(50, 100, ZX_BRIGHT_HIGH);
	// ZX_GFX_set_pixel_flash(50, 100, ZX_FLASH_ON);
	ZX_GFX_set_block_attributes(50, 100, 58, 108, ZX_COLOR_RED, ZX_COLOR_YELLOW, ZX_BRIGHT_HIGH, ZX_FLASH_OFF);

	while (1) {
	}
}
