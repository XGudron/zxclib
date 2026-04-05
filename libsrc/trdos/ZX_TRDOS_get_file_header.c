#include <string.h>
#include <zx_trdos.h>

void ZX_TRDOS_get_file_header(uint8_t file_num, zx_trdos_catalog_entry_t *fileinfo) {
	ZX_TRDOS_read_file_header(file_num);

	fileinfo->drive = ZX_TRDOS_get_drive_num();
	fileinfo->file_num = file_num;
	memcpy(fileinfo->filename, (volatile uint8_t *)ZX_TRDOS_FILEINFO_FILENAME, 8);
	fileinfo->type = *((volatile uint8_t *)ZX_TRDOS_FILEINFO_TYPE);
	fileinfo->start = *((volatile uint16_t *)ZX_TRDOS_FILEINFO_START);
	fileinfo->length = *((volatile uint16_t *)ZX_TRDOS_FILEINFO_LENGTH);
	fileinfo->sectors = *((volatile uint8_t *)ZX_TRDOS_FILEINFO_SECTORS);
	fileinfo->start_sector = *((volatile uint8_t *)ZX_TRDOS_FILEINFO_START_SECTOR);
	fileinfo->start_track = *((volatile uint8_t *)ZX_TRDOS_FILEINFO_START_TRACK);
}
