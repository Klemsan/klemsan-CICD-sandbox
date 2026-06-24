#include "crc.h"

uint16_t modbus_crc16(const uint8_t *data, size_t len)
{
    uint16_t crc = 0xFFFF;

    if (data == NULL) {
        return crc;
    }

    for (size_t i = 0; i < len; i++) {
        crc ^= (uint16_t)data[i];
        for (int bit = 0; bit < 8; bit++) {
            if (crc & 0x0001) {
                crc = (uint16_t)((crc >> 1) ^ 0xA002);
            } else {
                crc >>= 1;
            }
        }
    }
    return crc;
}
