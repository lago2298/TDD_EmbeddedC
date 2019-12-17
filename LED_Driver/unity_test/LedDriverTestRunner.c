#include "unity_fixture.h"

#if 1
TEST_GROUP_RUNNER(LedDriver)
{
    	RUN_TEST_CASE(LedDriver, LedsOffAfterCreate);
	RUN_TEST_CASE(LedDriver, TurnOnAnyLed);
	RUN_TEST_CASE(LedDriver, TurnOnMultipleLeds);
	RUN_TEST_CASE(LedDriver, TurnOnAllLeds);
	RUN_TEST_CASE(LedDriver, TurnOffAllLeds);
	RUN_TEST_CASE(LedDriver, TurnOffAnyLed);
	RUN_TEST_CASE(LedDriver, ReadLedMemory);
	RUN_TEST_CASE(LedDriver, WithinBounds);
	RUN_TEST_CASE(LedDriver, TurnOnOutOfBounds);
	RUN_TEST_CASE(LedDriver, TurnOffOutOfBounds);
	RUN_TEST_CASE(LedDriver, OutOfBoundsTurnOnLEDThrowsRuntimeError);
	RUN_TEST_CASE(LedDriver, OutOfBoundsTurnOffLEDThrowsRuntimeError);
	RUN_TEST_CASE(LedDriver, OutOfBoundsToDo);
}
#endif 
