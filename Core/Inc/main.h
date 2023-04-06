/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Key_K1_Pin GPIO_PIN_3
#define Key_K1_GPIO_Port GPIOE
#define Key_K0_Pin GPIO_PIN_4
#define Key_K0_GPIO_Port GPIOE
#define Triger_Pin GPIO_PIN_0
#define Triger_GPIO_Port GPIOC
#define Echo_Pin GPIO_PIN_1
#define Echo_GPIO_Port GPIOC
#define Echo_EXTI_IRQn EXTI1_IRQn
#define Led_D2_Pin GPIO_PIN_6
#define Led_D2_GPIO_Port GPIOA
#define Led_D3_Pin GPIO_PIN_7
#define Led_D3_GPIO_Port GPIOA
#define Laser_Input_Pin GPIO_PIN_8
#define Laser_Input_GPIO_Port GPIOB
#define XSHNUT_Pin GPIO_PIN_9
#define XSHNUT_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
#define Led_D2_ON HAL_GPIO_WritePin(Led_D2_GPIO_Port, Led_D2_Pin, GPIO_PIN_RESET)
#define Led_D2_OFF HAL_GPIO_WritePin(Led_D2_GPIO_Port, Led_D2_Pin, GPIO_PIN_SET)

#define Led_D3_ON HAL_GPIO_WritePin(Led_D3_GPIO_Port, Led_D3_Pin, GPIO_PIN_RESET)
#define Led_D3_OFF HAL_GPIO_WritePin(Led_D3_GPIO_Port, Led_D3_Pin, GPIO_PIN_SET)
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
