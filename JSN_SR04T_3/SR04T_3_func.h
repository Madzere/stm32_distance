/*
 * SR04T_3_func.h
 *
 *  Created on: Oct 29, 2022
 *      Author: palad
 */
#ifndef __SR04T_3_FUNC_H
#define __SR04T_3_FUNC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "main.h"
#include "tim.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
double Distans_SR04T(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __SR04T_3_FUNC_H */

