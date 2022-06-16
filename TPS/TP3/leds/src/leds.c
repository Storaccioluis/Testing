/**
 * @file leds.c
 * @author Storaccio Luis Sebastián (storaccioluis@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-06-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "leds.h"
#include "errores.h"

#define LED_TO_BIT_OFFSET (1U)
#define BIT_MASK (1U)
#define LEDS_ALL_OFF (0U)

static uint16_t *port;

/**
 * @brief ledToMask:
 * Función auxiliar que realiza desplazamiento de un BIT_MASK  hacia la izquierda (led - LED_TO_BIT_OFFSET) posiciones.
 * @param led
 * @return uint16_t
 */
uint16_t ledToMask(uint8_t led)
{
    return (BIT_MASK << (led - LED_TO_BIT_OFFSET));
}

/**
 * @brief ledsInit:
 * Función que inicializa todos los LEDs en cero (LEDS_ALL_OFF) y asigna la direccion del puerto de LEDs a port.
 *
 * @param dir
 */
void ledsInit(uint16_t *dir)
{
    port = dir;
    *port = LEDS_ALL_OFF;
}

/**
 * @brief oneLedTurnOn:
 * Función que enciende un LED (nBit).
 *
 * @param nBit
 */
void oneLedTurnOn(uint16_t nBit)
{
    if (nBit > 16)
    {
        Alerta("Número de LED inválido");
    }
    else
    {
        *port |= ledToMask(nBit);
    }
}

/**
 * @brief oneLedTurnOff:
 * Función que apaga un LED (nBit).
 *
 * @param nBit
 */
void oneLedTurnOff(uint16_t nBit)
{
    *port &= ~ledToMask(nBit);
}

/**
 * @brief allLedTurnOn:
 * Función que enciende todos los LEDs.
 */
void allLedTurnOn(void)
{
    *port |= 0xFFFF;
}

/**
 * @brief allLedTurnOff:
 * Función que apaga todos los LEDs.
 *
 */
void allLedTurnOff(void)
{
    *port &= 0x0000;
}
