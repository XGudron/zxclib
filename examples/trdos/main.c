/*
 Для работы демо в эмуляторе ZEsarUX необходимо включить Menu->Storage->betadisk->Betadisk enabled и подмонтировать trdos.trd
*/

#include "stdio.h"
#include "string.h"
#include "zxclib.h"

volatile uint8_t sector_buffer[256] = {1, 2, 3};
volatile uint8_t file_buffer[256];
uint8_t file_num;
zx_trdos_catalog_entry_t file_info;

void main() {
	ZX_48K_open_channel(ZX_CHANNEL_TOP);
	ZX_GFX_clear_screen();

	// Инициализация TR-DOS
	puts("MAKE SHURE BETADISK ENBL IN EMU!\r\r");

	puts("TR-DOS Init...");
	ZX_TRDOS_reset();
	puts("OK\r");

	puts("Select drive...");
	ZX_TRDOS_init_drive(0);
	if (ZX_TRDOS_get_drive_num() != 0) {
		puts("ERROR\r");
		return;
	}
	puts("OK\r");

	puts("Read system sector...");
	ZX_TRDOS_read_system_sector();
	puts("OK\r");

	puts("Select track...");
	ZX_TRDOS_select_track(10);
	puts("OK\r");

	puts("Select sector...");
	ZX_TRDOS_select_sector(20);
	if (ZX_TRDOS_get_sector_num() != 20) {
		puts("ERROR\r");
		return;
	}
	puts("OK\r");

	puts("Set buffer addr...");
	ZX_TRDOS_set_buffer_addr(sector_buffer);
	if (ZX_TRDOS_get_buffer_addr() != (uint16_t)sector_buffer) {
		puts("ERROR\r");
		return;
	}
	puts("OK\r");

	puts("Write sector...");
	sector_buffer[0] = 1;
	sector_buffer[1] = 2;
	sector_buffer[2] = 5;
	ZX_TRDOS_write_sectors(sector_buffer, 1, 20, 20);
	puts("OK\r");

	puts("Read sector...");
	sector_buffer[0] = 0;
	sector_buffer[1] = 0;
	sector_buffer[2] = 0;
	ZX_TRDOS_read_sectors(sector_buffer, 1, 20, 20);

	if (sector_buffer[0] != 1 || sector_buffer[1] != 2 || sector_buffer[2] != 5) {
		puts("ERROR\r");
		printf("%d %d %d\r", sector_buffer[0], sector_buffer[1], sector_buffer[2]);
		return;
	}
	puts("OK\r");

	puts("Print catalog... press any key");
	getchar();
	ZX_TRDOS_print_catalog(2);
	puts("Print catalog... OK\r");

	puts("Find file...");
	file_num = ZX_TRDOS_find_file("trdos   ", 't');
	if (file_num != 0) {
		puts("ERROR\r");
		printf("%d\r", file_num);
		return;
	}
	puts("OK\r");

	puts("Read file header...");
	ZX_TRDOS_get_file_header(file_num, &file_info);
	puts(file_info.filename);
	puts(" OK\r");

	puts("Write file header...");
	strcpy(file_info.filename, "test    ");
	ZX_TRDOS_set_file_header(&file_info);
	ZX_TRDOS_write_file_header(file_num);

	ZX_TRDOS_get_file_header(file_num, &file_info);
	puts(file_info.filename);
	puts(" OK\r");

	puts("Write code...");
	strcpy(file_info.filename, "code    ");
	file_info.type = 'C';
	ZX_TRDOS_set_file_header(&file_info);
	ZX_TRDOS_write_code(sector_buffer, sizeof(sector_buffer));
	file_num = ZX_TRDOS_find_file("code    ", 'C');
	if (file_num != 1) {
		puts("ERROR\r");
		printf("%d\r", file_num);
		return;
	}
	puts(" OK\r");

	puts("Write basic...");
	strcpy(file_info.filename, "basic   ");
	file_info.type = 'B';
	ZX_TRDOS_set_file_header(&file_info);
	ZX_TRDOS_write_basic(sector_buffer, sizeof(sector_buffer), 1);
	file_num = ZX_TRDOS_find_file("basic   ", 'B');
	if (file_num != 2) {
		puts("ERROR\r");
		printf("%d\r", file_num);
		return;
	}
	puts(" OK\r");

	puts("Read file...");
	ZX_TRDOS_get_file_header(1, &file_info);
	sector_buffer[0] = 0;
	sector_buffer[1] = 0;
	sector_buffer[2] = 0;
	ZX_TRDOS_read_file(sector_buffer, file_info.length);
	if (sector_buffer[0] != 1 || sector_buffer[1] != 2 || sector_buffer[2] != 5) {
		puts("ERROR\r");
		printf("%d %d %d %d %x %x\r", sector_buffer[0], sector_buffer[1], sector_buffer[2]);
		return;
	}
	puts("OK\r");

	puts("Read file part...");
	ZX_TRDOS_get_file_header(1, &file_info);
	file_buffer[0] = 0;
	file_buffer[1] = 0;
	file_buffer[2] = 0;
	ZX_TRDOS_read_file_partially(&file_info, sector_buffer, file_buffer, 1, 2);
	if (file_buffer[0] != 2 || file_buffer[1] != 5 || file_buffer[2] != 0) {
		puts("ERROR\r");
		printf("%d %d %d %d %x %x\r", file_buffer[0], file_buffer[1], file_buffer[2]);
		return;
	}
	puts("OK\r");

	puts("Delete file...");
	ZX_TRDOS_get_file_header(2, &file_info);
	ZX_TRDOS_delete_files();
	file_num = ZX_TRDOS_find_file("basic   ", 'B');
	if (file_num != 0xFF) {
		puts("ERROR\r");
		printf("%d\r", file_num);
		return;
	}
	puts("OK\r");

	puts("Check track...");
	ZX_TRDOS_set_top_side();
	ZX_TRDOS_set_bottom_side();
	uint8_t defected_tracks = ZX_TRDOS_check_track(10);
	if (defected_tracks != 0x0) {
		puts("ERROR\r");
		printf("%d\r", defected_tracks);
		return;
	}
	puts("OK\r");

	puts("\r");
	puts("Example completed\r");

	while (1) {
	}
}
