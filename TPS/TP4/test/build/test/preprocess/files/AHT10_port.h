#include "src/AHT10.h"
void AHT10_I2C_Init_Handler(void);

void AHT10_I2C_Send(uint8_t devAdd, uint8_t *pData, uint16_t Size, uint32_t Timeout);

void AHT10_I2C_Receive(uint8_t devAdd, uint8_t *pData, uint16_t Size, uint32_t Timeout);

void AHT10_I2C_Delay(uint32_t ret);

typedef 

       _Bool 

            bool_t;



typedef enum

{



    NonMaskableInt_IRQn = -14,

    MemoryManagement_IRQn = -12,

    BusFault_IRQn = -11,

    UsageFault_IRQn = -10,

    SVCall_IRQn = -5,

    DebugMonitor_IRQn = -4,

    PendSV_IRQn = -2,

    SysTick_IRQn = -1,



    WWDG_IRQn = 0,

    PVD_IRQn = 1,

    TAMP_STAMP_IRQn = 2,

    RTC_WKUP_IRQn = 3,

    FLASH_IRQn = 4,

    RCC_IRQn = 5,

    EXTI0_IRQn = 6,

    EXTI1_IRQn = 7,

    EXTI2_IRQn = 8,

    EXTI3_IRQn = 9,

    EXTI4_IRQn = 10,

    DMA1_Stream0_IRQn = 11,

    DMA1_Stream1_IRQn = 12,

    DMA1_Stream2_IRQn = 13,

    DMA1_Stream3_IRQn = 14,

    DMA1_Stream4_IRQn = 15,

    DMA1_Stream5_IRQn = 16,

    DMA1_Stream6_IRQn = 17,

    ADC_IRQn = 18,

    EXTI9_5_IRQn = 23,

    TIM1_BRK_TIM9_IRQn = 24,

    TIM1_UP_TIM10_IRQn = 25,

    TIM1_TRG_COM_TIM11_IRQn = 26,

    TIM1_CC_IRQn = 27,

    TIM2_IRQn = 28,

    TIM3_IRQn = 29,

    TIM4_IRQn = 30,

    I2C1_EV_IRQn = 31,

    I2C1_ER_IRQn = 32,

    I2C2_EV_IRQn = 33,

    I2C2_ER_IRQn = 34,

    SPI1_IRQn = 35,

    SPI2_IRQn = 36,

    USART1_IRQn = 37,

    USART2_IRQn = 38,

    EXTI15_10_IRQn = 40,

    RTC_Alarm_IRQn = 41,

    OTG_FS_WKUP_IRQn = 42,

    DMA1_Stream7_IRQn = 47,

    SDIO_IRQn = 49,

    TIM5_IRQn = 50,

    SPI3_IRQn = 51,

    DMA2_Stream0_IRQn = 56,

    DMA2_Stream1_IRQn = 57,

    DMA2_Stream2_IRQn = 58,

    DMA2_Stream3_IRQn = 59,

    DMA2_Stream4_IRQn = 60,

    OTG_FS_IRQn = 67,

    DMA2_Stream5_IRQn = 68,

    DMA2_Stream6_IRQn = 69,

    DMA2_Stream7_IRQn = 70,

    USART6_IRQn = 71,

    I2C3_EV_IRQn = 72,

    I2C3_ER_IRQn = 73,

    FPU_IRQn = 81,

    SPI4_IRQn = 84

} IRQn_Type;

typedef struct

{

    uint32_t CR1;

    uint32_t CR2;

    uint32_t OAR1;

    uint32_t OAR2;

    uint32_t DR;

    uint32_t SR1;

    uint32_t SR2;

    uint32_t CCR;

    uint32_t TRISE;

    uint32_t FLTR;

} I2C_TypeDef;



typedef struct

{

    uint32_t ClockSpeed;





    uint32_t DutyCycle;





    uint32_t OwnAddress1;





    uint32_t AddressingMode;





    uint32_t DualAddressMode;





    uint32_t OwnAddress2;





    uint32_t GeneralCallMode;





    uint32_t NoStretchMode;





} I2C_InitTypeDef;



typedef struct

{

    I2C_TypeDef *Instance;



    I2C_InitTypeDef Init;



    uint8_t *pBuffPtr;



    uint16_t XferSize;



    uint16_t XferCount;



    uint32_t XferOptions;



    uint32_t PreviousState;





    uint32_t ErrorCode;



    uint32_t Devaddress;



    uint32_t Memaddress;



    uint32_t MemaddSize;



    uint32_t EventCount;



} I2C_HandleTypeDef;
