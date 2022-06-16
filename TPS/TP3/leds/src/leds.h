
/**
 * @brief
 *
 * @param dir
 */
#ifndef _LEDS_H
#define _LEDS_H

#include <stdint.h>

void ledsInit(uint16_t *dir);

void oneLedTurnOn(uint16_t nBit);

void oneLedTurnOff(uint16_t nBit);



#endif