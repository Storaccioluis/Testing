/*
 * AHT10_Port.c
 *
 *  Created on: Apr 20, 2022
 *      Author: luis
 */
#include "AHT10_port.h"

I2C_HandleTypeDef hi2c1;


void AHT10_I2C_Init_Handler(void)
{
    hi2c1.Instance = I2C1;
    hi2c1.Init.ClockSpeed = 100000;
    hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
    hi2c1.Init.OwnAddress1 = 0;
    hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c1.Init.OwnAddress2 = 0;
    hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
    HAL_I2C_Init(&hi2c1);
}

AHT10_I2C_Send(uint8_t devAdd, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    HAL_I2C_Master_Transmit(&hi2c1, devAdd, &pData, Size, Timeout);
}
AHT10_I2C_Receive(uint8_t devAdd, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    HAL_I2C_Master_Transmit(&hi2c1, devAdd, &pData, Size, Timeout);
}

void AHT10_I2C_Delay(uint32_t ret)
{
    HAL_Delay(ret);
}