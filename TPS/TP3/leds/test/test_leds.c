/**
 * @file test_leds.c
 * @author Storaccio Luis Sebastián (storaccioluis@gmail.com)
 * @brief  Test uniario TP3
 * Driver de LEDs: test
    * Después de la inicialización de los LEDs deben quedar apagados.
    * Se puede prender un LED individual.
    * Se puede apagar un LED individual.
    * Se puede prender y apagar múltiples LEDs.
    * Se pueden prender todos los LEDs de una vez.
    * Se pueden apagar todos los LEDs de una vez.
    * Se puede consultar el estado de un LED.

 * @version 0.1
 * @date 2022-06-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "unity.h"
#include "leds.h"
#include "mock_errores.h"

static uint16_t ledsVirtuals;

/**
 * @brief Set the Up object
 *
 */
void setUp(void)
{
    ledsInit(&ledsVirtuals);
}
/**
 * @brief  test_all_leds_inits_off:
 * Todos los leds inicializan apagados.
 */
void test_all_leds_inits_off(void)
{
    uint16_t ledsVirtuals = 0xFFFF;
    ledsInit(&ledsVirtuals);
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuals);
}

/**
 * @brief test_one_led_on:
 * Se puede prender un LED individual.
 */
void test_one_led_on(void)
{
    oneLedTurnOn(5);
    TEST_ASSERT_EQUAL_HEX16(1 << 4, ledsVirtuals);
}

/**
 * @brief test_one_led_off:
 * Se puede apagar un LED individual.
 */
void test_one_led_off(void)
{
    oneLedTurnOn(5);
    oneLedTurnOff(5);
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuals);
}

/**
 * @brief test_turn_on_off_multiple_leds:
 * Se puede prender y apagar múltiples LEDs.
 *
 */
void test_turn_on_off_multiple_leds(void)
{
    oneLedTurnOn(5);
    oneLedTurnOn(5);
    oneLedTurnOn(11);
    oneLedTurnOff(3);
    oneLedTurnOff(11);
    TEST_ASSERT_EQUAL_HEX16(1 << 4, ledsVirtuals);
}
/**
 * @brief test_turn_on_all_leds:
 * Se pueden prender todos los LEDs de una vez.
 */
void test_turn_on_all_leds(void)
{
    allLedTurnOff();
    allLedTurnOn();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuals);
}

/**
 * @brief test_turn_off_all_leds:
 * Se pueden apagar todos los LEDs de una vez.
 */
void test_turn_off_all_leds(void)
{
    allLedTurnOn();
    allLedTurnOff();
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuals);
}

/**
 * @brief test_led_is_on:
 * Test para verificar si el estado de un led es encendido (getStateLed(led) return true).
 */
void test_is_led_on(void)
{
    bool ret = false;
    oneLedTurnOn(5);
    ret = getStateLed(5);
    TEST_ASSERT_EQUAL(true, ret);
}

/**
 * @brief test_led_is_off:
 *  Test para verificar si el estado de un led es apagado (getStateLed(led) return false).
 *
 */
void test_is_led_off(void)
{
    bool ret = false;
    allLedTurnOn();
    oneLedTurnOff(7);
    ret = getStateLed(7);
    TEST_ASSERT_EQUAL(false, ret);
}

/**
 * @brief test_invalid_upper_limit_ton_led:
 * Función que verifica que la funciones de error se llamen cuando se ingresa un valor fuera de los límites.
 *
 */
void test_invalid_upper_limit_ton_led(void)
{
    RegistrarMensaje_Expect(ALERTA, "oneLedTurnOn", 0, "Número de LED inválido");
    RegistrarMensaje_IgnoreArg_linea();
    oneLedTurnOn(17);
}
