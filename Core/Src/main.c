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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
int STATE			= 0x00;
int FORCE 		= 0x00;

int LOCK1_TRIGGER = 0x01;
int LOCK2_TRIGGER = 0x02;
int LOCK3_TRIGGER = 0x04;
int LOCK4_TRIGGER = 0x08;
int IRIS_LOW 		= 0x10;
int IRIS_HIGH 	= 0x20;
int Z_LOW 		= 0x40;
int Z_HIGH 		= 0x80;

int IRIS_CLOSE 	= 0x01;
int IRIS_OPEN 	= 0x02;
int THETA_CW		= 0x04;
int THETA_CCW		= 0x08;
int Z_LOWER		= 0x10;
int Z_HIGHER		= 0x20;
int RESET_STATE 		= 0x40;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int spin_motor(int motor, int dir){
	int delay_ms = 2;
	switch(motor){
		case 1:
			 HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, (dir ? GPIO_PIN_SET : GPIO_PIN_RESET));
			 HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_SET);
			 HAL_Delay(delay_ms);
			 HAL_GPIO_WritePin(STEP1_GPIO_Port, STEP1_Pin, GPIO_PIN_RESET);
			 HAL_Delay(delay_ms);
			 break;
		case 2:
			 HAL_GPIO_WritePin(DIR2_GPIO_Port, DIR2_Pin, (dir ? GPIO_PIN_SET : GPIO_PIN_RESET));
			 HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_SET);
			 HAL_Delay(delay_ms);
			 HAL_GPIO_WritePin(STEP2_GPIO_Port, STEP2_Pin, GPIO_PIN_RESET);
			 HAL_Delay(delay_ms);
			 break;
		case 3:
			 HAL_GPIO_WritePin(DIR3_GPIO_Port, DIR3_Pin, (dir ? GPIO_PIN_SET : GPIO_PIN_RESET));
			 HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_SET);
			 HAL_Delay(delay_ms);
			 HAL_GPIO_WritePin(STEP3_GPIO_Port, STEP3_Pin, GPIO_PIN_RESET);
			 HAL_Delay(delay_ms);
			 break;
		default:
			break;
	}
	return 0;
}

void lock_check(){
	if (HAL_GPIO_ReadPin(LOCK1_GPIO_Port, LOCK1_Pin)){
		HAL_GPIO_WritePin(EXT_LED1_GPIO_Port, EXT_LED1_Pin, GPIO_PIN_SET);
		STATE |= 1 << 0;
	} else if (HAL_GPIO_ReadPin(LOCK2_GPIO_Port, LOCK2_Pin)){
		HAL_GPIO_WritePin(EXT_LED2_GPIO_Port, EXT_LED2_Pin, GPIO_PIN_SET);
		STATE |= 1 << 1;
	} else if (HAL_GPIO_ReadPin(LOCK3_GPIO_Port, LOCK3_Pin)){
		HAL_GPIO_WritePin(EXT_LED3_GPIO_Port, EXT_LED3_Pin, GPIO_PIN_SET);
		STATE |= 1 << 2;
	} else if (HAL_GPIO_ReadPin(LOCK4_GPIO_Port, LOCK4_Pin)){
		HAL_GPIO_WritePin(EXT_LED4_GPIO_Port, EXT_LED4_Pin, GPIO_PIN_SET);
		STATE |= 1 << 3;
	}

}

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
  HAL_GPIO_WritePin(INT_LED1_GPIO_Port, INT_LED1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(INT_LED2_GPIO_Port, INT_LED2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(INT_LED3_GPIO_Port, INT_LED3_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(INT_LED4_GPIO_Port, INT_LED4_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(INT_LED5_GPIO_Port, INT_LED5_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(STEPPER_SLEEP_GPIO_Port, STEPPER_SLEEP_Pin, GPIO_PIN_SET);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		if (HAL_GPIO_ReadPin(IRIS_FORCE_LOW_GPIO_Port, IRIS_FORCE_LOW_Pin)){
			spin_motor(1, 0);

		}
		else if (HAL_GPIO_ReadPin(IRIS_FORCE_HIGH_GPIO_Port, IRIS_FORCE_HIGH_Pin)){
			spin_motor(1, 1);
		}

		if (HAL_GPIO_ReadPin(THETA_FORCE_CCW_GPIO_Port, THETA_FORCE_CCW_Pin)){
			spin_motor(2, 0);

		}
		else if (HAL_GPIO_ReadPin(THETA_FORCE_CW_GPIO_Port, THETA_FORCE_CW_Pin)){
			spin_motor(2, 1);
		}

		lock_check();
		if ((STATE & (1 << 0)) && (STATE & (1 << 1)) && (STATE & (1 << 2)) && (STATE & (1 << 3))){
			HAL_GPIO_WritePin(BLUE_GPIO_Port, GREEN_Pin, GPIO_PIN_SET);
		}
		HAL_Delay(10);
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, EXT_LED4_Pin|EXT_LED3_Pin|EXT_LED2_Pin|WHITE_Pin
                          |BLUE_Pin|GREEN_Pin|RED_Pin|STEPPER_SLEEP_Pin
                          |STEP1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(EXT_LED1_GPIO_Port, EXT_LED1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, STEPPER_EN_Pin|MS1_Pin|MS3_Pin|INT_LED1_Pin
                          |INT_LED2_Pin|INT_LED3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(MS2_GPIO_Port, MS2_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, DIR1_Pin|STEP2_Pin|DIR2_Pin|STEP3_Pin
                          |DIR3_Pin|INT_LED4_Pin|INT_LED5_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : EXT_LED4_Pin EXT_LED3_Pin EXT_LED2_Pin WHITE_Pin
                           BLUE_Pin GREEN_Pin RED_Pin STEPPER_SLEEP_Pin
                           STEP1_Pin */
  GPIO_InitStruct.Pin = EXT_LED4_Pin|EXT_LED3_Pin|EXT_LED2_Pin|WHITE_Pin
                          |BLUE_Pin|GREEN_Pin|RED_Pin|STEPPER_SLEEP_Pin
                          |STEP1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : EXT_LED1_Pin */
  GPIO_InitStruct.Pin = EXT_LED1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(EXT_LED1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : STATE_RESET_Pin IRIS_FORCE_LOW_Pin */
  GPIO_InitStruct.Pin = STATE_RESET_Pin|IRIS_FORCE_LOW_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : STEPPER_EN_Pin MS1_Pin MS2_Pin MS3_Pin
                           INT_LED1_Pin INT_LED2_Pin INT_LED3_Pin */
  GPIO_InitStruct.Pin = STEPPER_EN_Pin|MS1_Pin|MS2_Pin|MS3_Pin
                          |INT_LED1_Pin|INT_LED2_Pin|INT_LED3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : DIR1_Pin STEP2_Pin DIR2_Pin STEP3_Pin
                           DIR3_Pin INT_LED4_Pin INT_LED5_Pin */
  GPIO_InitStruct.Pin = DIR1_Pin|STEP2_Pin|DIR2_Pin|STEP3_Pin
                          |DIR3_Pin|INT_LED4_Pin|INT_LED5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : Z_LIM_LOW_Pin Z_LIM_HIGH_Pin IRIS_LIM_LOW_Pin IRIS_LIM_HIGH_Pin
                           Z_FORCE_LOW_Pin Z_FORCE_HIGH_Pin */
  GPIO_InitStruct.Pin = Z_LIM_LOW_Pin|Z_LIM_HIGH_Pin|IRIS_LIM_LOW_Pin|IRIS_LIM_HIGH_Pin
                          |Z_FORCE_LOW_Pin|Z_FORCE_HIGH_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : LOCK1_Pin LOCK2_Pin LOCK3_Pin LOCK4_Pin
                           IRIS_FORCE_HIGH_Pin THETA_FORCE_CW_Pin THETA_FORCE_CCW_Pin */
  GPIO_InitStruct.Pin = LOCK1_Pin|LOCK2_Pin|LOCK3_Pin|LOCK4_Pin
                          |IRIS_FORCE_HIGH_Pin|THETA_FORCE_CW_Pin|THETA_FORCE_CCW_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PB6 PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF0_USART1;
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
