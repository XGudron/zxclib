#include <string.h>
#include <zx_trdos.h>

void ZX_TRDOS_set_file_header(zx_trdos_catalog_entry_t *fileinfo) {
	memcpy((volatile uint8_t *)ZX_TRDOS_FILEINFO_FILENAME, fileinfo->filename, 8);
	*((volatile uint8_t *)ZX_TRDOS_FILEINFO_TYPE) = fileinfo->type;
	*((volatile uint16_t *)ZX_TRDOS_FILEINFO_START) = fileinfo->start;
	*((volatile uint16_t *)ZX_TRDOS_FILEINFO_LENGTH) = fileinfo->length;
	*((volatile uint8_t *)ZX_TRDOS_FILEINFO_SECTORS) = fileinfo->sectors;
	*((volatile uint8_t *)ZX_TRDOS_FILEINFO_START_SECTOR) = fileinfo->start_sector;
	*((volatile uint8_t *)ZX_TRDOS_FILEINFO_START_TRACK) = fileinfo->start_track;
}
