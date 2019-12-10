#ifndef LEDDRIVER_H
#define LEDDRIVER_H

#include <stdint.h>

void LedDriver_Create(uint16_t *address);

void LedDriver_TurnOn(uint8_t led_number);

void LedDriver_TurnOff(uint8_t led_number);

void LedDriver_TurnOnAllLeds(void);

void LedDriver_TurnOffAllLeds(void);

#endif /* LEDDRIVER_H */
