/**
 * @file leds.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-06-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "leds.h"

static uint16_t *port;

void ledsInit(uint16_t *dir)
{
    port = dir;
    *port = 0;
}

void oneLedTurnOn(uint16_t nBit)
{
    *port |= 1 << (nBit - 1);
}

void oneLedTurnOff(uint16_t nBit)
{
    *port &= ~(1 << (nBit - 1));
}
