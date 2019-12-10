#include "LedDriver.h"

#define CONVERT_LED_NUM_TO_BIT(n) (1 << (n-1))

enum led_state {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON}; // state of led

static uint16_t *ledsAddress;
static uint16_t ledsImage; // stores actual state from hardware

static void updateHardware(void)
{
	*ledsAddress = ledsImage;
}

void LedDriver_Create(uint16_t *address)
{
	ledsAddress = address;
	ledsImage = ALL_LEDS_OFF;
	updateHardware();
}

void LedDriver_TurnOn(uint8_t led_number)
{
	ledsImage |= CONVERT_LED_NUM_TO_BIT(led_number);
	updateHardware();
}

void LedDriver_TurnOff(uint8_t led_number)
{
	ledsImage &= ~CONVERT_LED_NUM_TO_BIT(led_number);
	updateHardware();
}

void LedDriver_TurnOnAllLeds(void)
{
	ledsImage = ALL_LEDS_ON;
	updateHardware();
}

void LedDriver_TurnOffAllLeds(void)
{
	LedDriver_TurnOn(15);
	ledsImage = ALL_LEDS_OFF;
	updateHardware();
}
