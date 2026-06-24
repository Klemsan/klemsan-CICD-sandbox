#include "unity.h"
#include "crc.h"

void setUp(void)    {}
void tearDown(void) {}

/* A real Modbus read-holding-registers request frame:
 * slave 0x01, func 0x03, addr 0x0000, count 0x000A */
void test_crc16_known_frame(void)
{
    uint8_t frame[] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x0A};
    TEST_ASSERT_EQUAL_HEX16(0xCDC5, modbus_crc16(frame, sizeof(frame)));
}

void test_crc16_empty_returns_init(void)
{
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, modbus_crc16(NULL, 0));
}

void test_crc16_single_byte(void)
{
    uint8_t b = 0x01;
    TEST_ASSERT_EQUAL_HEX16(0x807E, modbus_crc16(&b, 1));
}
