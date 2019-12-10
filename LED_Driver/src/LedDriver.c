#include "LedDriver.h"

#define CONVERT_LED_NUM_TO_BIT(n) (1 << (n-1))

enum led_state {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON}; // state of led

static uint16_t *ledsAddress;

void LedDriver_Create(uint16_t *address)
{
	ledsAddress = address;
	*ledsAddress = 0;
}

void LedDriver_TurnOn(uint8_t led_number)
{
	*ledsAddress |= CONVERT_LED_NUM_TO_BIT(led_number);
}

void LedDriver_TurnOff(uint8_t led_number)
{
	*ledsAddress &= ~CONVERT_LED_NUM_TO_BIT(led_number);
}

void LedDriver_TurnOnAllLeds(void)
{
	*ledsAddress = ALL_LEDS_ON;
}

void LedDriver_TurnOffAllLeds(void)
{
	LedDriver_TurnOn(15);
	*ledsAddress = ALL_LEDS_OFF;
}
