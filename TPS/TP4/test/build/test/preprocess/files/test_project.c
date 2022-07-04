#include "build/test/mocks/mock_AHT10_port.h"
#include "src/AHT10.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"










extern uint8_t buffer_read[6];

extern uint8_t buffer_transmission[3];

extern uint8_t buffer_read[6];

extern uint16_t size;











uint8_t buffer_transmission_compare[] = {0xE1, 0x08, 0x00};



uint8_t buffer_read_temperatura_compare[] = {0xAC, 0x33, 0x00};



uint8_t buffer_read_humidity_compare_command[] = {0xAC, 0x33, 0x00};













void test_init_buffer_transmission_AHT10(void)

{

    buffer_transmission[0] = 0xFF;

    buffer_transmission[1] = 0xFF;

    buffer_transmission[2] = 0xFF;

    AHT10_I2C_Init_Handler_CMockExpect(44);

    AHT10_I2C_Send_CMockIgnore();

    AHT10_I2C_Delay_CMockIgnore();

    AHT10_Init();

    UnityAssertEqualIntArray(( const void*)((buffer_transmission_compare)), ( const void*)((buffer_transmission)), (UNITY_UINT32)((3)), (

   ((void *)0)

   ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void test_init_size_transmission_AHT10(void)

{

    size = 0u;

    AHT10_I2C_Init_Handler_CMockExpect(59);

    AHT10_I2C_Send_CMockIgnore();

    AHT10_I2C_Delay_CMockIgnore();

    AHT10_Init();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0003)), (UNITY_INT)(UNITY_INT16)((size)), (

   ((void *)0)

   ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_HEX16);

}













void test_command_to_read_temp_AHT10(void)

{

    buffer_transmission[0] = 0xFF;

    buffer_transmission[1] = 0xFF;

    buffer_transmission[2] = 0xFF;

    AHT10_I2C_Send_CMockIgnore();

    AHT10_I2C_Delay_CMockIgnore();

    AHT10_I2C_Receive_CMockIgnore();

    AHT10_Read_Temp();

    UnityAssertEqualIntArray(( const void*)((buffer_read_temperatura_compare)), ( const void*)((buffer_transmission)), (UNITY_UINT32)((3)), (

   ((void *)0)

   ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void test_size_of_buffer_transmition_read_temperature_function_AHT10(void)

{

    size = 0u;

    buffer_transmission[0] = 0xFF;

    buffer_transmission[1] = 0xFF;

    buffer_transmission[2] = 0xFF;

    AHT10_I2C_Send_CMockIgnore();

    AHT10_I2C_Delay_CMockIgnore();

    AHT10_I2C_Receive_CMockIgnore();

    AHT10_Read_Temp();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0003)), (UNITY_INT)(UNITY_INT16)((size)), (

   ((void *)0)

   ), (UNITY_UINT)(98), UNITY_DISPLAY_STYLE_HEX16);

}

void test_convertion_data_read_in_temperature_celcius()

{

    float temperature = 0u;

    buffer_read[3] = 0b00000110;

    buffer_read[4] = 0b00000000;

    buffer_read[5] = 0b00000000;

    AHT10_I2C_Send_CMockIgnore();

    AHT10_I2C_Delay_CMockIgnore();

    AHT10_I2C_Receive_CMockIgnore();

    temperature = AHT10_Read_Temp();

    UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((25)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((25))), (UNITY_FLOAT)((UNITY_FLOAT)((temperature))), ((

   ((void *)0)

   )), (UNITY_UINT)((UNITY_UINT)(118)));

}













void test_size_of_buffer_transmition_read_humidity_function_AHT10(void)

{

    buffer_transmission[0] = 0xFF;

    buffer_transmission[1] = 0xFF;

    buffer_transmission[2] = 0xFF;

    AHT10_I2C_Send_CMockIgnore();

    AHT10_I2C_Delay_CMockIgnore();

    AHT10_I2C_Receive_CMockIgnore();

    AHT10_Read_Hum();

    UnityAssertEqualIntArray(( const void*)((buffer_read_humidity_compare_command)), ( const void*)((buffer_transmission)), (UNITY_UINT32)((3)), (

   ((void *)0)

   ), (UNITY_UINT)(135), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void test_size_of_buffer_transmition_read_hum_function_AHT10(void)

{

    size = 0u;

    buffer_transmission[0] = 0xFF;

    buffer_transmission[1] = 0xFF;

    buffer_transmission[2] = 0xFF;

    AHT10_I2C_Send_CMockIgnore();

    AHT10_I2C_Delay_CMockIgnore();

    AHT10_I2C_Receive_CMockIgnore();

    AHT10_Read_Hum();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0006)), (UNITY_INT)(UNITY_INT16)((size)), (

   ((void *)0)

   ), (UNITY_UINT)(153), UNITY_DISPLAY_STYLE_HEX16);

}













void test_convertion_data_read_in_humidity_percent(void)

{

    int humidity = 0u;

    buffer_read[1] = 0b10000000;

    buffer_read[2] = 0b00000000;

    buffer_read[3] = 0b00001111;

    AHT10_I2C_Send_CMockIgnore();

    AHT10_I2C_Delay_CMockIgnore();

    AHT10_I2C_Receive_CMockIgnore();

    humidity = AHT10_Read_Hum();

    UnityAssertEqualNumber((UNITY_INT)((50)), (UNITY_INT)((humidity)), (

   ((void *)0)

   ), (UNITY_UINT)(171), UNITY_DISPLAY_STYLE_INT);

}
