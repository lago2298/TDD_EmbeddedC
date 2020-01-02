#if 1
#include "unity_fixture.h"
#include "LedDriver.h"
#include "RuntimeErrorStub.h"

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

TEST(LedDriver, ReadLedMemory)
{
	virtualLeds = 0xffff;
	LedDriver_TurnOn(8); // turns on LED in actual LED memory
	TEST_ASSERT_EQUAL_HEX16(0x80, virtualLeds);
}

TEST(LedDriver, WithinBounds)
{
	LedDriver_TurnOn(1);
	LedDriver_TurnOn(16);
	TEST_ASSERT_EQUAL_HEX16(0x8001, virtualLeds);
}

TEST(LedDriver, TurnOnOutOfBounds)
{	
	LedDriver_TurnOn(0);
	LedDriver_TurnOn(43);
	LedDriver_TurnOn(-10);
	LedDriver_TurnOn(58);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LedDriver, TurnOffOutOfBounds)
{
	LedDriver_TurnOnAllLeds();	
	LedDriver_TurnOff(0);
	LedDriver_TurnOff(20);
	LedDriver_TurnOff(-2);
	LedDriver_TurnOff(200);
	TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);
}

TEST(LedDriver, OutOfBoundsTurnOnLEDThrowsRuntimeError)
{
	LedDriver_TurnOn(-1);
	TEST_ASSERT_EQUAL_STRING("Led Driver: out of bounds LED", RuntimeErrorStub_GetLastError());
	TEST_ASSERT_EQUAL(-1, RuntimeErrorStub_GetLastParameter());
}

TEST(LedDriver, OutOfBoundsTurnOffLEDThrowsRuntimeError)
{
	LedDriver_TurnOnAllLeds();	
	LedDriver_TurnOff(0);
	TEST_ASSERT_EQUAL_STRING("Led Driver: out of bounds LED", RuntimeErrorStub_GetLastError());
	TEST_ASSERT_EQUAL(0, RuntimeErrorStub_GetLastParameter());
	LedDriver_TurnOff(20);
	TEST_ASSERT_EQUAL_STRING("Led Driver: out of bounds LED", RuntimeErrorStub_GetLastError());
	TEST_ASSERT_EQUAL(20, RuntimeErrorStub_GetLastParameter());
}

TEST(LedDriver, LedDriverIsOn)
{
	TEST_ASSERT_FALSE(LedDriver_IsOn(11));
	LedDriver_TurnOn(11);
	TEST_ASSERT_TRUE(LedDriver_IsOn(11));
}

TEST(LedDriver, LedDriverIsOff)
{
	TEST_ASSERT_TRUE(LedDriver_IsOff(11));
	LedDriver_TurnOn(11);
	TEST_ASSERT_FALSE(LedDriver_IsOff(11));
}

TEST(LedDriver, OutOfBoundsLEDAlwaysOff)
{
	TEST_ASSERT_FALSE(LedDriver_IsOn(20));
	TEST_ASSERT_TRUE(LedDriver_IsOff(20));
}

#endif
