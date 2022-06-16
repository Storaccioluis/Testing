#include "build/test/mocks/mock_errores.h"
#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


static uint16_t ledsVirtuals;











void setUp(void)

{

    ledsInit(&ledsVirtuals);

}









void test_all_leds_inits_off(void)

{

    uint16_t ledsVirtuals = 0xFFFF;

    ledsInit(&ledsVirtuals);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuals)), (

   ((void *)0)

   ), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_HEX16);

}











void test_one_led_on(void)

{

    oneLedTurnOn(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 4)), (UNITY_INT)(UNITY_INT16)((ledsVirtuals)), (

   ((void *)0)

   ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_HEX16);

}











void test_one_led_off(void)

{

    oneLedTurnOn(5);

    oneLedTurnOff(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuals)), (

   ((void *)0)

   ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_HEX16);

}













void test_turn_on_off_multiple_leds(void)

{

    oneLedTurnOn(5);

    oneLedTurnOn(5);

    oneLedTurnOn(11);

    oneLedTurnOff(3);

    oneLedTurnOff(11);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 4)), (UNITY_INT)(UNITY_INT16)((ledsVirtuals)), (

   ((void *)0)

   ), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_HEX16);

}









void test_turn_on_all_leds(void)

{

    allLedTurnOff();

    allLedTurnOn();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((ledsVirtuals)), (

   ((void *)0)

   ), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_HEX16);

}











void test_turn_off_all_leds(void)

{

    allLedTurnOn();

    allLedTurnOff();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuals)), (

   ((void *)0)

   ), (UNITY_UINT)(99), UNITY_DISPLAY_STYLE_HEX16);

}











void test_led_is_on(void)

{

    oneLedTurnOn(5);

    do {if ((ledsVirtuals & 1 << 4)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(109)));}} while(0);

}













void test_led_is_off(void)

{

    oneLedTurnOff(11);

    do {if (!((ledsVirtuals & 1 << 10))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(120)));}} while(0);

}



void test_invalid_upper_limit_ton_led(void)

{

    RegistrarMensaje_CMockExpect(125, ALERTA, "oneLedTurnOn", 0, "Nmero de LED invlido");

    RegistrarMensaje_CMockIgnoreArg_linea(126);

    oneLedTurnOn(17);

}
