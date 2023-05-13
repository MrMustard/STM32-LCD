/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd.h"
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
static void MX_GPIO_Init(void);
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
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  //create the lcd object for 4 bits  and 16x2 mode
  lcd_t lcd_1= lcd_create_4_bit(D1_RS_GPIO_Port, D1_RW_GPIO_Port, D1_E_GPIO_Port,
  								D1_RS_Pin, D1_RW_Pin, D1_E_Pin,
  								D1_D7_GPIO_Port, D1_D6_GPIO_Port, D1_D5_GPIO_Port, D1_D4_GPIO_Port,
  								D1_D7_Pin,D1_D6_Pin, D1_D5_Pin,D1_D4_Pin,lcd_chr_16x2_mode);

  lcd_t lcd_2= lcd_create_4_bit(D2_RS_GPIO_Port, D2_RW_GPIO_Port, D2_E_GPIO_Port,
  								D2_RS_Pin, D2_RW_Pin, D2_E_Pin,
  								D2_D7_GPIO_Port, D2_D6_GPIO_Port, D2_D5_GPIO_Port, D2_D4_GPIO_Port,
  								D2_D7_Pin,D2_D6_Pin, D2_D5_Pin,D2_D4_Pin,lcd_chr_16x2_mode);
  lcd_clear(&lcd_1);//clear display 1
  lcd_clear(&lcd_2);//clear display 2
  lcd_set_cursor(&lcd_1, 0, 0);
  lcd_print_string(&lcd_1, "TEST LCD 1");
  lcd_set_cursor(&lcd_1, 1, 0);
  lcd_print_string(&lcd_1, "4 bit mode 16x2");

  lcd_set_cursor(&lcd_2, 0, 0);
  lcd_print_string(&lcd_2, "TEST LCD 2");
  lcd_set_cursor(&lcd_2, 1, 0);
  lcd_print_string(&lcd_2, "4 bit mode 16x2");
  uint8_t counter_1=0;//var to show counter in lcd
  char buffer_1 [16];
  uint8_t counter_2=0;//var to show counter in lcd
  char buffer_2 [16];
  HAL_Delay(1500);
  lcd_clear(&lcd_1);//clear lcd
  lcd_clear(&lcd_2);//clear lcd
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

/*Display 1*/
	  sprintf(buffer_1,"%3d",counter_1);
	  lcd_set_cursor(&lcd_1, 0, 0);
	  lcd_print_string(&lcd_1, "Counter:");
	  lcd_set_cursor(&lcd_1, 0, 9);
	  lcd_print_string(&lcd_1,buffer_1 );
	 counter_1++;


/*Display 2*/
	  sprintf(buffer_2,"%3d",counter_2);
	  lcd_set_cursor(&lcd_2, 0, 0);
	  lcd_print_string(&lcd_2, "Counter:");
	  lcd_set_cursor(&lcd_2, 0, 9);
	  lcd_print_string(&lcd_2,buffer_2 );
	 counter_2++;
	 HAL_Delay(1000);

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
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, D2_RS_Pin|D2_RW_Pin|D2_E_Pin|D2_D4_Pin
                          |D1_RS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, D2_D5_Pin|D2_D6_Pin|D2_D7_Pin|D1_D6_Pin
                          |D1_D7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, D1_RW_Pin|D1_E_Pin|D1_D4_Pin|D1_D5_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : D2_RS_Pin D2_RW_Pin D2_E_Pin D2_D4_Pin
                           D1_RS_Pin */
  GPIO_InitStruct.Pin = D2_RS_Pin|D2_RW_Pin|D2_E_Pin|D2_D4_Pin
                          |D1_RS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : D2_D5_Pin D2_D6_Pin D2_D7_Pin D1_D6_Pin
                           D1_D7_Pin */
  GPIO_InitStruct.Pin = D2_D5_Pin|D2_D6_Pin|D2_D7_Pin|D1_D6_Pin
                          |D1_D7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : D1_RW_Pin D1_E_Pin D1_D4_Pin D1_D5_Pin */
  GPIO_InitStruct.Pin = D1_RW_Pin|D1_E_Pin|D1_D4_Pin|D1_D5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

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