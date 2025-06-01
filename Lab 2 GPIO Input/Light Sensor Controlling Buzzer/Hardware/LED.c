#include "stm32f10x.h"                  // Device header

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2); // Turn off LED
}

void LED1_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_1);		// PA1 = LOW
}

void LED1_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_1);		//
}

void LED1_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1) == 0)		//
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_1);					
	}
	else													
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);					
	}
}

void LED2_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);		// PA1 = LOW
}

void LED2_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_2);		//
}

void LED2_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_2) == 0)		//
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_2);					
	}
	else													
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);					
	}
}
