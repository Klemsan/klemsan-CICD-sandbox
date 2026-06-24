#ifndef CRC_H
#define CRC_H

#include <stdint.h>
#include <stddef.h>

/* Modbus RTU CRC-16 (poly 0xA001, init 0xFFFF) */
uint16_t modbus_crc16(const uint8_t *data, size_t len);

#endif /* CRC_H */

