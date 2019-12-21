#ifndef LEDDRIVER_H
#define LEDDRIVER_H

#include <stdint.h>
#include <stdbool.h>

void LedDriver_Create(uint16_t *address);

void LedDriver_TurnOn(int8_t led_number);

void LedDriver_TurnOff(int8_t led_number);

void LedDriver_TurnOnAllLeds(void);

void LedDriver_TurnOffAllLeds(void);

#endif /* LEDDRIVER_H */
