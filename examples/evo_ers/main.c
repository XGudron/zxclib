#include "zxclib.h"
#include <stdint.h>
#include <stdio.h>

const zx_evo_window_t test_window = {
    .X_COORD = 20,
    .Y_COORD = 5,
    .V_SIZE = 10,
    .H_SIZE = 10,
    .COLOR_WIN = ZX_COLOR_GREEN,
    .COLOR_CUR = ZX_COLOR_RED,
    .FLAGS = ZX_EVO_WINFLAGS_DOWN_HEADER | ZX_EVO_WINFLAGS_UPHEADER,
    .NUM_PKT = 0,
    .TEK_PKT = 0,
    .PKT_COUNT = 0,
    .ADR_TXT = "TEST TEXT",
    .ADR_PRG = 0,
    .ADR_MOUSE = 0,
    .ADR_HOTKEY = 0,
};

const uint8_t test_palette[16] = {0x10, 0x31, 0x52, 0x73, 0xA0, 0xC1, 0xE2, 0x03, 0xF0, 0xF1, 0xF2, 0xF3, 0x00, 0x01, 0x02, 0x03};

char test_string[32] = "";
uint8_t test_file_pointer[32];
uint8_t test_buffer[256];

void main(void) {
	ZX_GFX_clear_screen();

	// Демонстрация базовых функций 48K
	ZX_GFX_fill_screen(ZX_COLOR_GREEN, ZX_COLOR_BLACK, ZX_BRIGHT_HIGH, ZX_FLASH_OFF);
	ZX_set_border(ZX_COLOR_BLACK);

	ZX_EVO_print("\x16\x00\x00"); // reset cursor position
	ZX_EVO_print("\x03ZX Spectrum Evolution Demo\r");
	ZX_EVO_print("\x16\x01\x28============================\r");
	printf("Test stdio...OK\r");

	// ZX_EVO_printer_init();
	// ZX_EVO_printer_putchar('Z');
	// ZX_EVO_printer_put_token(1);
	// ZX_EVO_printer_print_screen();

	// ZX_EVO_type_init();
	// ZX_EVO_type_emul();

	// ZX_EVO_scroll_up(1);
	// ZX_EVO_scroll_down(1);

	printf("Test setMode...");
	ZX_EVO_set_mode(ZX_EVO_TXTSCR_MODE | ZX_EVO_TURBO_MAX | ZX_EVO_MEM_MODE_PENT);
	printf("OK\r");

	printf("Test math functions...");
	uint16_t res_div16 = ZX_EVO_divide16(3000, 4);
	if (res_div16 != 750) {
		printf("ERROR %d", res_div16);
		return;
	}
	uint32_t res_mul16 = ZX_EVO_multiply16(3000, 400);
	if (res_mul16 != 1200000) {
		printf("ERROR %d", res_mul16);
		return;
	}
	uint32_t res_div32 = ZX_EVO_divide32(123456789, 80000);
	if (res_div32 != 1543) {
		printf("ERROR %d", res_div32);
		return;
	}
	res_div32 = ZX_EVO_divide32_remainder(31, 20);
	if (res_div32 != 11) {
		printf("ERROR %d", res_div32);
		return;
	}
	uint32_t res_mul32 = ZX_EVO_multiply32(8000, 80000);
	if (res_mul32 != 640000000) {
		printf("ERROR %d", res_mul32);
		return;
	}
	printf("OK\r");

	ZX_EVO_uint32_to_str(test_string, 640000000);
	printf(test_string);
	printf(" ");
	ZX_EVO_uint16_to_str(test_string, 64000);
	printf(test_string);
	printf(" ");
	ZX_EVO_uint8_to_str(test_string, 64);
	printf(test_string);
	printf("\r");

	uint32_t version = ZX_EVO_get_version();
	printf("FW Ver %x.%x.%x\r", (version >> 16) & 0xFF, (version >> 8) & 0xFF, (version >> 0) & 0xFF);

	printf("Test dev manager...\r");
	ZX_EVO_devmanager_find();
	ZX_EVO_devmanager_set_volume(0);
	uint8_t vol_count = ZX_EVO_devmanager_get_volume_count();
	printf("Vol count: %d\r", vol_count);
	ZX_EVO_devmanager_get_volume_table(test_buffer);
	// ZX_EVO_devmanager_call_driver();
	// ZX_EVO_devmanager_set_bits();
	// ZX_EVO_devmanager_sd_present();
	// ZX_EVO_devmanager_call_hdd_driver();
	// ZX_EVO_devmanager_volume_reinit();
	// ZX_EVO_devmanager_set_sector();

	printf("Test FAT...\r");
	// ZX_EVO_fat_init // do not use
	ZX_EVO_fat_get_pointer(test_file_pointer, 0);
	// ZX_EVO_fat_enter_directory
	ZX_EVO_fat_get_path(test_buffer);
	printf("%s\r", test_buffer);
	ZX_EVO_fat_get_fullname(test_buffer);
	printf("%s ", test_buffer);
	uint16_t file_pos = ZX_EVO_fat_find_by_name("Ab");
	printf("%d ", file_pos);
	ZX_EVO_fat_find_set_extension(0, test_buffer);
	uint16_t find_count = ZX_EVO_fat_find_in_directory();
	printf("%d ", find_count);
	ZX_EVO_fat_open_file();
	uint8_t end = ZX_EVO_fat_read_file(1, test_buffer);
	printf("%d ", end);
	// ZX_EVO_fat_init_cluster // do not use
	uint16_t count = ZX_EVO_fat_call_position_function(5, 0);
	printf("%d\r", count);
	ZX_EVO_fat_go_root();
	// ZX_EVO_sort_findfiles

	printf("Test mount...");
	ZX_EVO_mount_open(0);
	ZX_EVO_mount_rdwr(0, 1, 2, test_buffer);
	ZX_EVO_mount_find();
	ZX_EVO_mount_get(test_buffer);
	ZX_EVO_mount_close(0);
	ZX_EVO_mount_load_image();
	ZX_EVO_mount_nameload(test_buffer);
	// ZX_EVO_mount_compare_drive
	// ZX_EVO_mount_virtual_drive_bits
	// ZX_EVO_mount_ramdisk
	// ZX_EVO_install_fatboot(test_buffer);
	printf("OK\r");

	printf("Test CMOS...");
	ZX_EVO_cmos_init();
	ZX_EVO_cmos_write(0xF0, 5);
	uint8_t cmos_res = ZX_EVO_cmos_read(0xF0);
	if (cmos_res != 5) {
		printf("ERROR %d", cmos_res);
		return;
	}
	// ZX_EVO_cmos_reset();
	printf("OK\r");

	printf("Test font&pallete...\r");
	ZX_EVO_setup_palette(test_palette);
	for (uint32_t i = 0; i < 200000; i++) {
	}
	ZX_EVO_setup_palette_zxdefault();
	ZX_EVO_setup_font(0, 0);
	printf("ATM \x8F\x90\x88\x82\x85\x92 font\r");
	ZX_EVO_setup_font(1, 0);
	printf("CP866 \x8F\x90\x88\x82\x85\x92 font\r");

	printf("Test window...OK\r");
	ZX_EVO_draw_window(&test_window);
	ZX_EVO_print("\x16\x04\x00");

	while (1) {
	}
}
