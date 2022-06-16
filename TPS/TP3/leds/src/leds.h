
#ifndef _LEDS_H
#define _LEDS_H

/**
 * @file leds.h
 * @author Storaccio Luis Sebastián (storaccioluis@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-06-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdint.h>

/**
 * @brief Función para inicializar leds
 *
 * @param dir: dirección de la variable que representa el puerto de 16 bits de LEDs.
 */
void ledsInit(uint16_t *dir);

/**
 * @brief Función que enciende un LED en particular.
 *
 * @param nBit: número del LED a encender, se representa como una posición del bit dentro de la palabra.
 */
void oneLedTurnOn(uint16_t nBit);

/**
 * @brief Funcion que apaga un LED en particular.
 *
 * @param nBit: número del LED a apagar, se representa como una posición del bit dentro de la palabra.
 */
void oneLedTurnOff(uint16_t nBit);

/**
 * @brief allLedTurnOn:
 * Función que enciende todos los LEDs.
 */
void allLedTurnOn(void);

/**
 * @brief allLedTurnOff:
 * Función que apaga todos los LEDs.
 */
void allLedTurnOff(void);

#endif