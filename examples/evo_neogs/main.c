#include "zxclib.h"
#include <stdint.h>
#include <stdio.h>

static zx_trdos_catalog_entry_t file_info;
uint8_t __at(0xC000) file_buffer[16384];
uint8_t sector_buffer[256];

static void load_mod_file(char *filename);

void main(void) {
	ZX_GFX_clear_screen();

	// Демонстрация базовых функций 48K
	ZX_GFX_fill_screen(ZX_COLOR_GREEN, ZX_COLOR_BLACK, ZX_BRIGHT_HIGH, ZX_FLASH_OFF);
	ZX_set_border(ZX_COLOR_BLACK);

	ZX_EVO_print("\x16\x00\x00"); // reset cursor position
	ZX_EVO_print("\x03ZX Spectrum NeoGS Demo\r");
	ZX_EVO_print("\x16\x01\x28============================\r");

	ZX_EVO_toggle_memory_dispatcher(true);
	ZX_EVO_select_mode(ZX_EVO_MODE_PENTAGON_1024);
	ZX_EVO_set_cpu_speed(ZX_EVO_CPU_14MHZ);
	ZX_EVO_set_video_mode(ZX_EVO_VIDEOMODE_ZX_STANDARD);

	ZX_EVO_print("Init General sound...\r");
	ZX_GS_warm_restart();
	uint32_t total_ram = ZX_GS_get_total_ram();
	printf("Total RAM: %lu\r", total_ram);
	uint32_t free_ram = ZX_GS_get_free_ram();
	printf("Free RAM: %lu\r", free_ram);
	uint8_t ram_pages = ZX_GS_get_ram_pages();
	printf("RAM pages: %u\r", ram_pages);
	ZX_48K_recover_IY();
	if (ZX_NEOGS_sd_is_card_present()) {
		ZX_EVO_print("NeoGS SD found\r");
	}
	if (ZX_NEOGS_mp3_player_check()) {
		ZX_EVO_print("NeoGS has MP3 player\r");
	}
	ZX_EVO_print("\r");

	// ZX_NEOGS_set_CPU_speed(ZX_NEOGS_CONFIG_CPU_24MHZ);

	ZX_EVO_print("Test Covox...\r");
	ZX_GS_enter_covox_mode();
	for (uint16_t i = 0; i < 65000; i++) {
		ZX_GS_covox_output(i, i);
	}
	ZX_GS_exit_covox_mode();
	ZX_EVO_print("\r");

	ZX_EVO_print("Load MOD to memory...\r");

	ZX_TRDOS_init_drive(0);
	if (ZX_TRDOS_get_drive_num() != 0) {
		ZX_EVO_print("Failed to mount drive A\r");
		return;
	}
	ZX_TRDOS_read_system_sector();

	ZX_disable_interrupts();
	uint8_t module_handle = ZX_GS_load_module_start();
	printf("MOD handle: %u\r", module_handle);
	ZX_48K_recover_IY();
	load_mod_file("mod1    ");
	load_mod_file("mod2    ");
	load_mod_file("mod3    ");
	load_mod_file("mod4    ");
	load_mod_file("mod5    ");
	load_mod_file("mod6    ");
	ZX_GS_load_module_end();
	ZX_enable_interrupts();

	free_ram = ZX_GS_get_free_ram();
	printf("Free RAM: %lu\r", free_ram);
	ZX_EVO_print("\r");

	ZX_EVO_print("Play MOD...\r");
	ZX_GS_set_module_master_volume(ZX_GS_VOLUME_MAX);
	ZX_GS_play_module(module_handle);
	ZX_EVO_print("\r");

	ZX_EVO_print("Demo completed !\r");

	while (1) {
	}
}

static void load_mod_file(char *filename) {
	uint8_t file_num = ZX_TRDOS_find_file(filename, 'm');
	ZX_TRDOS_get_file_header(file_num, &file_info);
	ZX_EVO_print("Loading: ");
	ZX_EVO_print(filename);
	ZX_EVO_print("\r");

	uint16_t remaining = file_info.length;
	uint16_t offset = 0;
	while (remaining > 0) {
		uint16_t block_size = MIN(remaining, sizeof(file_buffer));
		ZX_TRDOS_read_file_partially(&file_info, sector_buffer, file_buffer, offset, block_size);
		ZX_GS_load_module_data(file_buffer, block_size);
		offset += block_size;
		remaining -= block_size;
	}
}