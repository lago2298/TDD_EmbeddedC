#if 1
#include "unity_fixture.h"
#include "LedDriver.h"

static uint16_t virtualLeds;

TEST_GROUP(LedDriver);

TEST_SETUP(LedDriver)
{
	LedDriver_Create(&virtualLeds);
}

TEST_TEAR_DOWN(LedDriver)
{
}

// Verifies that after initializing LED driver, all LEDs are set to OFF (0)
TEST(LedDriver, LedsOffAfterCreate)
{
   	uint16_t virtualLeds = 0xffff; // 16 LEDs, 1 for each bit, set initial value to 1
   	LedDriver_Create(&virtualLeds);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LedDriver, TurnOnAnyLed)
{
	LedDriver_TurnOn(2);
	TEST_ASSERT_EQUAL_HEX16(0x0002, virtualLeds);
}

TEST(LedDriver, TurnOffAnyLed)
{
	LedDriver_TurnOnAllLeds();
	LedDriver_TurnOff(8);
	TEST_ASSERT_EQUAL_HEX16(0xff7f, virtualLeds);
}

// Turn multiple LEDs on
TEST(LedDriver, TurnOnMultipleLeds)
{
	LedDriver_TurnOn(8);
	LedDriver_TurnOn(9);
	TEST_ASSERT_EQUAL_HEX16(0x180, virtualLeds);
}

// Turn on all LEDs
TEST(LedDriver, TurnOnAllLeds)
{
	LedDriver_TurnOnAllLeds();
	TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);
}

// Turn off all LEDs
TEST(LedDriver, TurnOffAllLeds)
{
	LedDriver_TurnOffAllLeds();
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}
#endif
