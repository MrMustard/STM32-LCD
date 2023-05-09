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
#include "serial.h"
#include "led.h"
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
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
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
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  //SerialUartInit();
  //lcd_init();//inicializamos la pantalla
  //lcd_clear();
  //lcd_return_home();
  SerialUartSendString("Iniciando programa\n");
  led_off(led_status);
  led_all_on();
  HAL_Delay(100);
  led_all_off();
  HAL_Delay(100);
  led_on(led_status);

  uint8_t variable_1=0;
  uint8_t buffer_1[16];
  uint8_t variable_2=0;
  uint8_t buffer_2[16];

//we have to desing the pins and port toc reate lcd
//first we have to create a lcd_t varaible, this varaible recevive all the configuration data


/*
 lcd_t lcd_1= lcd_create_4_bit(	RSD_GPIO_Port, RWD_GPIO_Port, ED_GPIO_Port,
		  	  	  	  	  	  	  	RSD_Pin, RWD_Pin, ED_Pin,
									D7D_GPIO_Port, D6D_GPIO_Port, D5D_GPIO_Port, D4D_GPIO_Port,
									D7D_Pin, D6D_Pin, D5D_Pin, D4D_Pin, lcd_chr_16x2_mode);
									*/

  lcd_t lcd_1 = lcd_create_8_bit( RSD_GPIO_Port, RWD_GPIO_Port, ED_GPIO_Port,
		  	  	  	  	  	  	  RSD_Pin, RWD_Pin, ED_Pin,
								  D7D_GPIO_Port, D6D_GPIO_Port,D5D_GPIO_Port,D4D_GPIO_Port,
								  D3D_GPIO_Port, D2D_GPIO_Port,D1D_GPIO_Port,D0D_GPIO_Port,
								  D7D_Pin,D6D_Pin,D5D_Pin,D4D_Pin,
								  D3D_Pin,D2D_Pin,D1D_Pin,D0D_Pin, lcd_chr_16x2_mode);


  lcd_t lcd_2 = lcd_create_4_bit(	RS_D2_GPIO_Port, RW_D2_GPIO_Port, EN_D2_GPIO_Port,
		  	  	  	  	  	  	    RS_D2_Pin, RW_D2_Pin, EN_D2_Pin,
									D7_D2_GPIO_Port, D6_D2_GPIO_Port, D5_D2_GPIO_Port, D4_D2_GPIO_Port,
									D7_D2_Pin, D6_D2_Pin, D5_D2_Pin, D4_D2_Pin, lcd_chr_16x2_mode);
  lcd_clear(&lcd_1);
  lcd_clear(&lcd_2);
  lcd_return_home(&lcd_1);
  lcd_return_home(&lcd_2);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  //lcd_return_home();
	 // lcd_set_cursor(0, 0);
	  //lcd_print_string((uint8_t *)" PRUEBA ");
	  //HAL_Delay(1000);
	  //variable=button_read();
	  //lcd_set_cursor(0, 0);
	  //lcd_print_string((uint8_t *)"Valor de botones");
	  //lcd_set_cursor(1, 0);
	  //sprintf(buffer,"%3d",variable);
	 // lcd_print_string(buffer);
	  //HAL_Delay(100);

	 lcd_set_cursor(&lcd_1, 0, 0);
	  lcd_print_string(&lcd_1, "PRUEBA 1");
	  lcd_set_cursor(&lcd_1, 1, 0);
	  lcd_print_string(&lcd_1, "LCD 1");
	  sprintf(buffer_1,"%3d",variable_1);
	  lcd_set_cursor(&lcd_1, 1, 6);
	  lcd_print_string(&lcd_1, buffer_1);
	  variable_1++;
	  lcd_set_cursor(&lcd_1, 0, 15);
	  lcd_print_string(&lcd_1, "<");


	  lcd_set_cursor(&lcd_2, 0, 0);
	  lcd_print_string(&lcd_2, "PRUEBA 1");
	  lcd_set_cursor(&lcd_2, 1, 0);
	  lcd_print_string(&lcd_2, "LCD 2");
	  sprintf(buffer_2,"%3d",variable_2);
	  lcd_set_cursor(&lcd_2, 1, 6);
	  lcd_print_string(&lcd_2, buffer_2);
	  variable_2++;
	  lcd_set_cursor(&lcd_2, 0, 15);
	  lcd_print_string(&lcd_2, "*");


	/* prueba++;
	  send_to_lcd(&lcd_1,prueba,1);
	  HAL_Delay(10);*/
	 /* HAL_GPIO_WritePin(D7D_GPIO_Port, D7D_Pin, 1);
	  HAL_GPIO_WritePin(D6D_GPIO_Port, D6D_Pin, 1);
	  HAL_GPIO_WritePin(D5D_GPIO_Port, D5D_Pin, 1);
	  HAL_GPIO_WritePin(D4D_GPIO_Port, D4D_Pin, 1);
	  HAL_GPIO_WritePin(D3D_GPIO_Port, D3D_Pin, 1);
	  HAL_GPIO_WritePin(D2D_GPIO_Port, D2D_Pin, 1);
	  HAL_GPIO_WritePin(D1D_GPIO_Port, D1D_Pin, 0);
	  HAL_GPIO_WritePin(D0D_GPIO_Port, D0D_Pin, 1);*/









	 /* lcd_set_cursor_p(&lcd_1, 0, 0);
	  lcd_set_cursor_p(&lcd_2, 0, 0);

	  lcd_print_string_p(&lcd_1, "PRUEBA 1");
	  lcd_print_string_p(&lcd_2, "PRUEBA 1");
	  lcd_set_cursor_p(&lcd_1, 1, 0);
	  lcd_set_cursor_p(&lcd_2, 1, 0);
	  lcd_print_string_p(&lcd_1, "DATA:");
	  lcd_print_string_p(&lcd_2, "DATA:");
	  lcd_set_cursor_p(&lcd_1, 0, 15);
	  lcd_set_cursor_p(&lcd_2, 0, 15);
	  lcd_print_string_p(&lcd_1, "<");
	  lcd_print_string_p(&lcd_2, "<");*/








	 //  HAL_Delay(1000);
	  //lcd_clear();
	  //HAL_Delay(1000);

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
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV1;
  RCC_OscInitStruct.PLL.PLLN = 8;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, led_red_Pin|led_yellow_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, led_green_Pin|RS_D2_Pin|RW_D2_Pin|EN_D2_Pin
                          |D4_D2_Pin|D0D_Pin|D1D_Pin|D2D_Pin
                          |D3D_Pin|RSD_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, D5_D2_Pin|D6_D2_Pin|D7_D2_Pin|led_status_Pin
                          |D6D_Pin|D7D_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, RWD_Pin|ED_Pin|D4D_Pin|D5D_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : led_red_Pin led_yellow_Pin */
  GPIO_InitStruct.Pin = led_red_Pin|led_yellow_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : led_green_Pin RS_D2_Pin RW_D2_Pin EN_D2_Pin
                           D4_D2_Pin D0D_Pin D1D_Pin D2D_Pin
                           D3D_Pin RSD_Pin */
  GPIO_InitStruct.Pin = led_green_Pin|RS_D2_Pin|RW_D2_Pin|EN_D2_Pin
                          |D4_D2_Pin|D0D_Pin|D1D_Pin|D2D_Pin
                          |D3D_Pin|RSD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : D5_D2_Pin D6_D2_Pin D7_D2_Pin led_status_Pin
                           D6D_Pin D7D_Pin */
  GPIO_InitStruct.Pin = D5_D2_Pin|D6_D2_Pin|D7_D2_Pin|led_status_Pin
                          |D6D_Pin|D7D_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : RWD_Pin ED_Pin D4D_Pin D5D_Pin */
  GPIO_InitStruct.Pin = RWD_Pin|ED_Pin|D4D_Pin|D5D_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : button_1_Pin button_2_Pin button_3_Pin button_4_Pin
                           button_5_Pin */
  GPIO_InitStruct.Pin = button_1_Pin|button_2_Pin|button_3_Pin|button_4_Pin
                          |button_5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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
