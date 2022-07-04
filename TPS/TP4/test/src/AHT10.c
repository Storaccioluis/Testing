/*
 * AHT10.c
 *
 *  Created on: Apr 20, 2022
 *      Author: Storaccio luis
 */

#include "AHT10.h"
#include "AHT10_port.h"

uint8_t buffer_read[6];
uint8_t buffer_transmission[3];
const uint32_t timeout = 100;
uint16_t size;
uint16_t size_read;
float temperatura = -50;
int humedad = -50;

/**
 * @brief AHT10  Funcion de inicialización
 * @param None
 * @retval None
 */
void AHT10_Init(void)
{
  AHT10_I2C_Init_Handler();
  buffer_transmission[0] = AHT10_INIT_CMD;
  buffer_transmission[1] = 0x08;
  buffer_transmission[2] = AHT10_DATA_NOP;
  size = sizeof(buffer_transmission) / sizeof(uint8_t);
  AHT10_I2C_Send(AHT10_ADDRESS,buffer_transmission,size,timeout);
  AHT10_I2C_Delay(200);
} 

/**
 * @brief AHT10  Funcion lectura de temperatura
 * @param None
 * @retval float temperatura
 */
float AHT10_Read_Temp(void)
{ // Inicializar comunicación//
  buffer_transmission[0] = AHT10_START_MEASURMENT_CMD;
  buffer_transmission[1] = AHT10_DATA_MEASURMENT_CMD;
  buffer_transmission[2] = AHT10_DATA_NOP;
  size = sizeof(buffer_transmission) / sizeof(uint8_t);
  AHT10_I2C_Send(AHT10_ADDRESS,buffer_transmission,size,timeout);
  AHT10_I2C_Delay(10);
  size_read = sizeof(buffer_read) / sizeof(uint8_t);
  AHT10_I2C_Receive(AHT10_ADDRESS,buffer_read,size_read,timeout);
  return temperatura = ((((uint32_t)(buffer_read[3] & 0x0F) << 16) | ((uint16_t)buffer_read[4] << 8) | buffer_read[5]) * 200 / 1048576) - 50; // 20-bit raw temperature data
}
/**
 * @brief AHT10  Funcion lectura de humedad
 * @param None
 * @retval int humedad
 */
int AHT10_Read_Hum(void)
{ // Inicializar comunicación//
  buffer_transmission[0] = AHT10_START_MEASURMENT_CMD;
  buffer_transmission[1] = AHT10_DATA_MEASURMENT_CMD;
  buffer_transmission[2] = AHT10_DATA_NOP;
  AHT10_I2C_Send(AHT10_ADDRESS,buffer_transmission,3,timeout);
  AHT10_I2C_Delay(10);
  size = sizeof(buffer_read) / sizeof(uint8_t);
  AHT10_I2C_Receive(AHT10_ADDRESS,buffer_read,size,timeout);
  return humedad = ((((buffer_read[1] << 16) | (buffer_read[2] << 8) | buffer_read[3]) >> 4) * 100 / 1048576); // 20-bit raw temperature data
}