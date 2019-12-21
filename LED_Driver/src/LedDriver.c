#include "LedDriver.h"
#include "RuntimeError.h"

#define CONVERT_LED_NUM_TO_BIT(n) (1 << (n-1))

enum led_state {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON}; // state of led
enum led_numbers {FIRST_LED = 1, LAST_LED = 16};

static uint16_t *ledsAddress;
static uint16_t ledsImage; // stores actual state from hardware

static void updateHardware(void)
{
	*ledsAddress = ledsImage;
}

static bool isLedNumberOutOfBounds(int8_t led_number)
{
	return (led_number < 1 || led_number > 16);
}

static void setLedImageBit(int8_t led_number)
{
	ledsImage |= CONVERT_LED_NUM_TO_BIT(led_number);
}

static void clearLedImageBit(int8_t led_number)
{
	ledsImage &= ~CONVERT_LED_NUM_TO_BIT(led_number);
}

void LedDriver_Create(uint16_t *address)
{
	ledsAddress = address;
	ledsImage = ALL_LEDS_OFF;
	updateHardware();
}

void LedDriver_TurnOn(int8_t led_number)
{
	if (isLedNumberOutOfBounds(led_number))
	{
		RUNTIME_ERROR("Led Driver: out of bounds LED", led_number);
		return;
	}
	setLedImageBit(led_number);
	updateHardware();
}

void LedDriver_TurnOff(int8_t led_number)
{
	if (isLedNumberOutOfBounds(led_number))
	{
		RUNTIME_ERROR("Led Driver: out of bounds LED", led_number);
		return;
	}
	clearLedImageBit(led_number);
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
