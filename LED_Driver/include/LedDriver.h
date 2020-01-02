#ifndef LEDDRIVER_H
#define LEDDRIVER_H

#include <stdint.h>
#include <stdbool.h>

void LedDriver_Create(uint16_t *address);

void LedDriver_TurnOn(int8_t led_number);

void LedDriver_TurnOff(int8_t led_number);

void LedDriver_TurnOnAllLeds(void);

void LedDriver_TurnOffAllLeds(void);

bool LedDriver_IsOn(int8_t led_number);

bool LedDriver_IsOff(int8_t led_number);

#endif /* LEDDRIVER_H */
