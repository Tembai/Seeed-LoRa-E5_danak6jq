/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
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
#include "app_lorawan.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "sys_app.h"
#include "stm32wlxx_hal.h"
#include "stdint.h"
#include "stdlib.h"


//#include "..\..\STM32CubeIDE\Application\User\Core/sensor_app.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

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
  MX_LoRaWAN_Init();
  MX_I2C2_Init();
  /* USER CODE BEGIN 2 */
//  I2C_software_reset();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */


//	uint8_t reg[2], var[1];
//	static const uint8_t addr_write = 0x5D << 1;
//	static const uint8_t addr_read = (0x5D << 1)+1;	// address LPS33HW with read bit


//	ret=platform_read(&hi2c2, 0x0f, reg, 1);
//	ret=platform_write(&hi2c2, 0x11, 0x4, 1);
//	HAL_Delay(100);
//	ret=platform_read(&hi2c2, 0x11, reg, 1);

  uint8_t reg[2];

  while (1)
  {
    /* USER CODE END WHILE */
//    MX_LoRaWAN_Process();

    /* USER CODE BEGIN 3 */

	  Sensor_Data();

	  HAL_Delay(2000);

//	reg[0]=0x0f;
//
//	ret=platform_read(&hi2c2, reg[0], reg, 0);
//
//	APP_LOG(TS_OFF, VLEVEL_M, "reg 2 waarde vóór oneshot (functie): %x\n",reg[0]);

//	reg[0]=0x0F;
//	ret=HAL_I2C_Master_Transmit(&hi2c2, (uint8_t)(0x76<<1), reg, 1, 1000);				// data lezen
//	if(!ret){
//		ret=HAL_I2C_Master_Receive(&hi2c2, (uint8_t)((0x76<<1)+1), reg, 1, 1000);
	}
//	APP_LOG(TS_OFF, VLEVEL_M, "reg 2 waarde vóór oneshot (direct): %x\n",reg[0]);


	  /*

	reg[0]=0x11;
	reg[1]=0x11;
	ret=HAL_I2C_Master_Transmit(&hi2c2, addr_write, reg, 2, 1000);				// one shot


//	reg[0]=0x28;
	ret=platform_read(&hi2c2, 0x28, reg, 1);

	APP_LOG(TS_OFF, VLEVEL_M, "  reg 2 waarde na oneshot (functie): %x\n",reg[0]);

	HAL_Delay(50);
	reg[0]=0x28;
	ret=HAL_I2C_Master_Transmit(&hi2c2, addr_write, reg, 1, 1000);				// data lezen
	if(!ret){
		ret=HAL_I2C_Master_Receive(&hi2c2, addr_read, reg, 1, 1000);
	}
	APP_LOG(TS_OFF, VLEVEL_M, "  reg 2 waarde ná oneshot (direct): %x\n",reg[0]);
*/



//	  Sensor_Init();
//	  I2C_id();





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

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);
  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_11;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the SYSCLKSource, HCLK, PCLK1 and PCLK2 clocks dividers
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK3|RCC_CLOCKTYPE_HCLK
                              |RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1
                              |RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.AHBCLK3Divider = RCC_SYSCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

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

