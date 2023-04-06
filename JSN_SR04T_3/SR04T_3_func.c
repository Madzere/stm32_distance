/*
 * SR04T_3_func.c
 *
 *  Created on: Oct 29, 2022
 *      Author: palad
 */
#include "SR04T_3_func.h"
volatile uint8_t Flag_Timer = 0;
volatile uint8_t Flag_Echo_Compl = 0;
volatile uint32_t Timer_CNT = 0;
volatile uint32_t Enable = 0;
#define Speed 343
//#define Distance_Per_uSec  0.0343



double Distans_SR04T(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{
	double distanceCm = 0;
  Enable = 1;
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);
	HAL_TIM_Base_Start(&htim7);
	while(htim7.Instance->CNT < 20)
	{}
	HAL_TIM_Base_Stop(&htim7);
	htim7.Instance->CNT = 0;
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
	HAL_TIM_Base_Start(&htim14);
	while(1)
		{
			if(Flag_Echo_Compl == 1)
				{
					distanceCm = (Timer_CNT / 58.0);
					break;
				}
			else if(htim14.Instance->CNT > 50000)
				{
					distanceCm = 0;
					break;
				}
		}
	Flag_Echo_Compl = 0;
	HAL_TIM_Base_Stop(&htim14);
	htim14.Instance->CNT = 0;
	Enable = 0;
	return distanceCm;
}



void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == Echo_Pin)
	{
		if(Enable)
		{
			if(Flag_Timer == 0)
				{
					HAL_TIM_Base_Start(&htim6);
					Flag_Timer = 1;
				}
			else
				{
					HAL_TIM_Base_Stop(&htim6);
					Timer_CNT = htim6.Instance->CNT;
					htim6.Instance->CNT = 0;
					Flag_Timer = 0;
					Flag_Echo_Compl = 1;
				}
		}
	}
}
