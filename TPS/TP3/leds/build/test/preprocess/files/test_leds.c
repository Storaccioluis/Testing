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

   ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_HEX16);

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

   ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_HEX16);

}













void test_turn_on_off_multiple_leds(void)

{

    oneLedTurnOn(5);

    oneLedTurnOn(5);

    oneLedTurnOn(11);

    oneLedTurnOff(3);

    oneLedTurnOff(11);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1<<4)), (UNITY_INT)(UNITY_INT16)((ledsVirtuals)), (

   ((void *)0)

   ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_HEX16);

}
