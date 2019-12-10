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
}
#endif 