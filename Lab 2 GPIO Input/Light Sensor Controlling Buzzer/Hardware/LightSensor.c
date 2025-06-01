#include "stm32f10x.h"                  // Device header

/**
  * Function: Light sensor initialization
  * Parameters: None
  * Return value: None
  */
void LightSensor_Init(void)
{
	/* Enable clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);       // Enable the clock for GPIOB
	
	/* GPIO initialization */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);                      // Initialize PB13 as input with pull-up
}

/**
  * Function: Get the current high/low level output from the light sensor
  * Parameters: None
  * Return value: Output level of the light sensor, range: 0/1
  */
uint8_t LightSensor_Get(void)
{
	return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13);           // Return the input register status of PB13
}