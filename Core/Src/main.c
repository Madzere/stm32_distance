/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "SR04T_3_func.h"
#include "VL53L0_func.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdio.h"
#include "vl53l0x_api.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
    uint32_t refSpadCount;
    uint8_t isApertureSpads;
    uint8_t VhvSettings;
    uint8_t PhaseCal;
		
		uint8_t Message[64];
		uint8_t MessageLen;

		VL53L0X_RangingMeasurementData_t RangingData;
		VL53L0X_Dev_t  vl53l0x_c; // center module
		VL53L0X_DEV    Dev = &vl53l0x_c;


	
		
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
double Dist = 0;
char Buffer[100];
uint8_t size = 0;
uint8_t Key_counter = 0;
uint8_t while_inout = 0;
uint8_t n = 50;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void init_LV53L0 (void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM6_Init();
  MX_USART1_UART_Init();
  MX_TIM7_Init();
  MX_I2C1_Init();
  MX_I2C2_Init();
  MX_TIM14_Init();
  MX_TIM5_Init();
  /* USER CODE BEGIN 2 */
//uint8_t Message[64];
//uint8_t MessageLen;

//VL53L0X_RangingMeasurementData_t RangingData;
//VL53L0X_Dev_t  vl53l0x_c; // center module
//VL53L0X_DEV    Dev = &vl53l0x_c;


// Dev->I2cHandle = &hi2c1;
//  Dev->I2cDevAddr = 0x52;

//  HAL_GPIO_WritePin(XSHNUT_GPIO_Port, XSHNUT_Pin, GPIO_PIN_RESET); // Disable XSHUT
//  HAL_Delay(20);
//  HAL_GPIO_WritePin(XSHNUT_GPIO_Port, XSHNUT_Pin, GPIO_PIN_SET); // Enable XSHUT
//  HAL_Delay(20);



//  VL53L0X_WaitDeviceBooted( Dev );
//  VL53L0X_DataInit( Dev );
//  VL53L0X_StaticInit( Dev );
//  VL53L0X_PerformRefCalibration(Dev, &VhvSettings, &PhaseCal);
//  VL53L0X_PerformRefSpadManagement(Dev, &refSpadCount, &isApertureSpads);
//  VL53L0X_SetDeviceMode(Dev, VL53L0X_DEVICEMODE_SINGLE_RANGING);

//  // Enable/Disable Sigma and Signal check
//  VL53L0X_SetLimitCheckEnable(Dev, VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, 1);
//  VL53L0X_SetLimitCheckEnable(Dev, VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, 1);
//  VL53L0X_SetLimitCheckValue(Dev, VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, (FixPoint1616_t)(0.1*65536));
//  VL53L0X_SetLimitCheckValue(Dev, VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, (FixPoint1616_t)(60*65536));
//  VL53L0X_SetMeasurementTimingBudgetMicroSeconds(Dev, 33000);
//  VL53L0X_SetVcselPulsePeriod(Dev, VL53L0X_VCSEL_PERIOD_PRE_RANGE, 18);
//  VL53L0X_SetVcselPulsePeriod(Dev, VL53L0X_VCSEL_PERIOD_FINAL_RANGE, 14);
//	
//	VL53L0X_PerformSingleRangingMeasurement(Dev, &RangingData);

//	  if(RangingData.RangeStatus == 0)
//	  {
//		  MessageLen = sprintf((char*)Message, "Measured distance: %i\n\r", RangingData.RangeMilliMeter);
//		  HAL_UART_Transmit(&huart1, Message, MessageLen, 100);
//	  }
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		if(HAL_GPIO_ReadPin(Key_K1_GPIO_Port,Key_K1_Pin) == GPIO_PIN_RESET && Key_counter == 0)//SR04T
			{
			  Led_D2_OFF;
			  Led_D3_OFF;
				while_inout = 0;	
				while(while_inout == 0)
				{
//					HAL_TIM_Base_Start(&htim5);
					Dist = Distans_SR04T(Triger_GPIO_Port,Triger_Pin);
//					HAL_TIM_Base_Stop(&htim5);
//					htim5.Instance->CNT = 0;
					HAL_Delay(20);
//					size = sprintf((void*)Buffer,"%f\r\n",(float)Dist);
//					HAL_UART_Transmit(&huart1, (uint8_t*)Buffer, size, 1000);
//					if((HAL_GPIO_ReadPin(Key_K0_GPIO_Port,Key_K0_Pin) == GPIO_PIN_RESET))
//						{
//							HAL_Delay(200);								
//							while(HAL_GPIO_ReadPin(Key_K0_GPIO_Port,Key_K0_Pin) == GPIO_PIN_RESET){} 
//							while_inout = 1;
//						}
				}								
			}
		else if(HAL_GPIO_ReadPin(Key_K1_GPIO_Port,Key_K1_Pin) == GPIO_PIN_RESET && Key_counter == 1)//LV53L0_I2C1
			{
				Led_D2_OFF;
				Led_D3_OFF;
				HAL_Delay(500);
				Led_D2_ON;
				Led_D3_OFF;
				while_inout = 0;
				init_LV53L0();
				while(while_inout == 0)
				{
					VL53L0X_PerformSingleRangingMeasurement(Dev, &RangingData);
					if(RangingData.RangeStatus == 0)
					{
						MessageLen = sprintf((char*)Message, "Measured distance: %i\n\r", RangingData.RangeMilliMeter);
						HAL_UART_Transmit(&huart1, Message, MessageLen, 100);
					}
					
					if((HAL_GPIO_ReadPin(Key_K0_GPIO_Port,Key_K0_Pin) == GPIO_PIN_RESET))
						{
							HAL_Delay(200);								
							while(HAL_GPIO_ReadPin(Key_K0_GPIO_Port,Key_K0_Pin) == GPIO_PIN_RESET){} 
							while_inout = 1;								
						}
				}								
			}	
		else if(HAL_GPIO_ReadPin(Key_K1_GPIO_Port,Key_K1_Pin) == GPIO_PIN_RESET && Key_counter == 2)//LV53L0_I2C2
			{
				Led_D2_OFF;
				Led_D3_OFF;
				HAL_Delay(500);
				Led_D2_OFF;
				Led_D3_ON;
				while_inout = 0;				
				while(while_inout == 0)
				{
					Dist = Distans_SR04T(Triger_GPIO_Port,Triger_Pin);
					size = sprintf((void*)Buffer,"%f\r\n",(float)Dist);
					HAL_UART_Transmit(&huart1, (uint8_t*)Buffer, size, 1000);
					
					if((HAL_GPIO_ReadPin(Key_K0_GPIO_Port,Key_K0_Pin) == GPIO_PIN_RESET))
						{
							HAL_Delay(200);								
							while(HAL_GPIO_ReadPin(Key_K0_GPIO_Port,Key_K0_Pin) == GPIO_PIN_RESET){} 
							while_inout = 1;								
						}
				}
			}	
		else if(HAL_GPIO_ReadPin(Key_K1_GPIO_Port,Key_K1_Pin) == GPIO_PIN_RESET && Key_counter == 3)//WaveShare Laser Sensor
			{
				Led_D2_OFF;
				Led_D3_OFF;
				HAL_Delay(500);
				Led_D2_ON;
				Led_D3_ON;		
				while_inout = 0;				
				while(while_inout == 0)
				{
					if(HAL_GPIO_ReadPin(Laser_Input_GPIO_Port,Laser_Input_Pin) == GPIO_PIN_RESET)							
							HAL_UART_Transmit(&huart1, (uint8_t*)"See\r\n", sizeof("See\r\n"), 1000);
					else
							HAL_UART_Transmit(&huart1, (uint8_t*)"Dont See\r\n",sizeof("Dont See\r\n"), 1000);
					if((HAL_GPIO_ReadPin(Key_K0_GPIO_Port,Key_K0_Pin) == GPIO_PIN_RESET))
						{
							HAL_Delay(200);								
							while(HAL_GPIO_ReadPin(Key_K0_GPIO_Port,Key_K0_Pin) == GPIO_PIN_RESET){} 
							while_inout = 1;
						}				
				}			
			}				
		if(HAL_GPIO_ReadPin(Key_K0_GPIO_Port,Key_K0_Pin) == GPIO_PIN_RESET)
			{
				HAL_Delay(200);
				while(HAL_GPIO_ReadPin(Key_K0_GPIO_Port,Key_K0_Pin) == GPIO_PIN_RESET){} 
				Key_counter++;
				if(Key_counter > 3)
					Key_counter = 0;
				
				if(Key_counter == 1)
					{
						Led_D2_ON;
						Led_D3_OFF;
					}
				else if(Key_counter == 2)
					{
						Led_D2_OFF;
						Led_D3_ON;
					}
				else if(Key_counter == 3)
					{
						Led_D2_ON;
						Led_D3_ON;
					}
				else
					{
						Led_D2_OFF;
						Led_D3_OFF;
					}
			}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV4;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void init_LV53L0 (void)
{
	Dev->I2cHandle = &hi2c1;
	Dev->I2cDevAddr = 0x52;	

  HAL_GPIO_WritePin(XSHNUT_GPIO_Port, XSHNUT_Pin, GPIO_PIN_RESET); // Disable XSHUT
  HAL_Delay(20);
  HAL_GPIO_WritePin(XSHNUT_GPIO_Port, XSHNUT_Pin, GPIO_PIN_SET); // Enable XSHUT
  HAL_Delay(20);



  VL53L0X_WaitDeviceBooted( Dev );
  VL53L0X_DataInit( Dev );
  VL53L0X_StaticInit( Dev );
  VL53L0X_PerformRefCalibration(Dev, &VhvSettings, &PhaseCal);
  VL53L0X_PerformRefSpadManagement(Dev, &refSpadCount, &isApertureSpads);
  VL53L0X_SetDeviceMode(Dev, VL53L0X_DEVICEMODE_SINGLE_RANGING);

  // Enable/Disable Sigma and Signal check
  VL53L0X_SetLimitCheckEnable(Dev, VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, 1);
  VL53L0X_SetLimitCheckEnable(Dev, VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, 1);
  VL53L0X_SetLimitCheckValue(Dev, VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, (FixPoint1616_t)(0.1*65536));
  VL53L0X_SetLimitCheckValue(Dev, VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, (FixPoint1616_t)(60*65536));
  VL53L0X_SetMeasurementTimingBudgetMicroSeconds(Dev, 33000);
  VL53L0X_SetVcselPulsePeriod(Dev, VL53L0X_VCSEL_PERIOD_PRE_RANGE, 18);
  VL53L0X_SetVcselPulsePeriod(Dev, VL53L0X_VCSEL_PERIOD_FINAL_RANGE, 14);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
