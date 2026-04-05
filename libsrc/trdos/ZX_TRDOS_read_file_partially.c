#include <zx_trdos.h>
#include <string.h>

void ZX_TRDOS_read_file_partially(zx_trdos_catalog_entry_t *file_info, uint8_t sector_buffer[256], uint8_t *dest_addr, uint32_t offset, uint16_t length) {
	// Проверяем, что offset не выходит за пределы файла
	if (offset >= file_info->length) {
		return; // Ничего не читаем, offset за пределами файла
	}
	
	// Корректируем длину, если она выходит за пределы файла
	uint16_t available_length = file_info->length - offset;
	if (length > available_length) {
		length = available_length;
	}
	
	// Вычисляем начальный сектор и смещение внутри сектора
	uint32_t start_sector_abs = offset / 256;
	uint8_t offset_in_sector = offset % 256;
	
	// Вычисляем абсолютный начальный сектор файла
	uint16_t file_start_sector = file_info->start_track * 16 + file_info->start_sector;
	uint16_t abs_start_sector = file_start_sector + start_sector_abs;
	
	// Вычисляем количество секторов для чтения
	uint16_t sectors_to_read = (length + offset_in_sector + 255) / 256;
	
	// Вычисляем начальную дорожку и сектор
	uint8_t start_track = abs_start_sector / 16;
	uint8_t start_sector = abs_start_sector % 16;
	
	// Счётчики
	uint8_t *current_dest = dest_addr;
	uint16_t bytes_copied = 0;
	
	// Если есть смещение внутри первого сектора
	if (offset_in_sector > 0) {
		// Читаем первый сектор
		ZX_TRDOS_read_sectors(sector_buffer, 1, start_sector, start_track);
		
		// Копируем нужную часть
		uint8_t copy_from_first = 256 - offset_in_sector;
		if (copy_from_first > length) {
			copy_from_first = length;
		}

		memcpy(current_dest, &sector_buffer[offset_in_sector], copy_from_first);
		
		bytes_copied = copy_from_first;
		current_dest += copy_from_first;
		
		// Переходим к следующему сектору
		start_sector++;
		if (start_sector >= 16) {
			start_sector = 0;
			start_track++;
		}
		sectors_to_read--;
	}
	
	// Читаем полные секторы
	while (sectors_to_read > 0 && bytes_copied < length) {
		uint8_t sectors_this_pass = sectors_to_read;
		if (sectors_this_pass > (16 - start_sector)) {
			sectors_this_pass = 16 - start_sector; // Не больше чем до конца дорожки
		}
		
		// Вычисляем сколько байт копировать из последнего сектора
		uint16_t remaining_bytes = length - bytes_copied;
		uint8_t bytes_in_last_sector = remaining_bytes % 256;
		
		if (sectors_this_pass == 1 && bytes_in_last_sector > 0 && (bytes_copied + 256) > length) {
			// Последний сектор, читаем во временный буфер и копируем часть
			ZX_TRDOS_read_sectors(sector_buffer, 1, start_sector, start_track);
			
			uint8_t copy_bytes = bytes_in_last_sector;
			if (copy_bytes > remaining_bytes) {
				copy_bytes = remaining_bytes;
			}
			
			memcpy(current_dest, sector_buffer, copy_bytes);
			
			bytes_copied += copy_bytes;
		} else {
			// Читаем полные секторы напрямую
			ZX_TRDOS_read_sectors(current_dest, sectors_this_pass, start_sector, start_track);
			
			uint16_t bytes_added = sectors_this_pass * 256;
			if (bytes_added > remaining_bytes) {
				bytes_added = remaining_bytes;
			}
			
			bytes_copied += bytes_added;
			current_dest += bytes_added;
		}
		
		// Переходим к следующей дорожке если нужно
		start_sector += sectors_this_pass;
		if (start_sector >= 16) {
			start_sector = 0;
			start_track++;
		}
		sectors_to_read -= sectors_this_pass;
	}
}
