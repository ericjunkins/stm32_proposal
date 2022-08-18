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
#include "stm32f0xx_hal.h"

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
#define EXT_LED4_Pin GPIO_PIN_13
#define EXT_LED4_GPIO_Port GPIOC
#define EXT_LED3_Pin GPIO_PIN_14
#define EXT_LED3_GPIO_Port GPIOC
#define EXT_LED2_Pin GPIO_PIN_15
#define EXT_LED2_GPIO_Port GPIOC
#define EXT_LED1_Pin GPIO_PIN_0
#define EXT_LED1_GPIO_Port GPIOF
#define WHITE_Pin GPIO_PIN_0
#define WHITE_GPIO_Port GPIOC
#define BLUE_Pin GPIO_PIN_1
#define BLUE_GPIO_Port GPIOC
#define GREEN_Pin GPIO_PIN_2
#define GREEN_GPIO_Port GPIOC
#define RED_Pin GPIO_PIN_3
#define RED_GPIO_Port GPIOC
#define STATE_RESET_Pin GPIO_PIN_3
#define STATE_RESET_GPIO_Port GPIOA
#define STEPPER_EN_Pin GPIO_PIN_4
#define STEPPER_EN_GPIO_Port GPIOA
#define MS1_Pin GPIO_PIN_5
#define MS1_GPIO_Port GPIOA
#define MS2_Pin GPIO_PIN_6
#define MS2_GPIO_Port GPIOA
#define MS3_Pin GPIO_PIN_7
#define MS3_GPIO_Port GPIOA
#define STEPPER_SLEEP_Pin GPIO_PIN_4
#define STEPPER_SLEEP_GPIO_Port GPIOC
#define STEP1_Pin GPIO_PIN_5
#define STEP1_GPIO_Port GPIOC
#define DIR1_Pin GPIO_PIN_0
#define DIR1_GPIO_Port GPIOB
#define STEP2_Pin GPIO_PIN_1
#define STEP2_GPIO_Port GPIOB
#define DIR2_Pin GPIO_PIN_2
#define DIR2_GPIO_Port GPIOB
#define STEP3_Pin GPIO_PIN_10
#define STEP3_GPIO_Port GPIOB
#define DIR3_Pin GPIO_PIN_11
#define DIR3_GPIO_Port GPIOB
#define Z_LIM_LOW_Pin GPIO_PIN_12
#define Z_LIM_LOW_GPIO_Port GPIOB
#define Z_LIM_HIGH_Pin GPIO_PIN_13
#define Z_LIM_HIGH_GPIO_Port GPIOB
#define IRIS_LIM_LOW_Pin GPIO_PIN_14
#define IRIS_LIM_LOW_GPIO_Port GPIOB
#define IRIS_LIM_HIGH_Pin GPIO_PIN_15
#define IRIS_LIM_HIGH_GPIO_Port GPIOB
#define LOCK1_Pin GPIO_PIN_6
#define LOCK1_GPIO_Port GPIOC
#define LOCK2_Pin GPIO_PIN_7
#define LOCK2_GPIO_Port GPIOC
#define LOCK3_Pin GPIO_PIN_8
#define LOCK3_GPIO_Port GPIOC
#define LOCK4_Pin GPIO_PIN_9
#define LOCK4_GPIO_Port GPIOC
#define INT_LED1_Pin GPIO_PIN_8
#define INT_LED1_GPIO_Port GPIOA
#define INT_LED2_Pin GPIO_PIN_11
#define INT_LED2_GPIO_Port GPIOA
#define INT_LED3_Pin GPIO_PIN_12
#define INT_LED3_GPIO_Port GPIOA
#define IRIS_FORCE_LOW_Pin GPIO_PIN_15
#define IRIS_FORCE_LOW_GPIO_Port GPIOA
#define IRIS_FORCE_HIGH_Pin GPIO_PIN_10
#define IRIS_FORCE_HIGH_GPIO_Port GPIOC
#define THETA_FORCE_CW_Pin GPIO_PIN_11
#define THETA_FORCE_CW_GPIO_Port GPIOC
#define THETA_FORCE_CCW_Pin GPIO_PIN_12
#define THETA_FORCE_CCW_GPIO_Port GPIOC
#define Z_FORCE_LOW_Pin GPIO_PIN_3
#define Z_FORCE_LOW_GPIO_Port GPIOB
#define Z_FORCE_HIGH_Pin GPIO_PIN_4
#define Z_FORCE_HIGH_GPIO_Port GPIOB
#define INT_LED4_Pin GPIO_PIN_8
#define INT_LED4_GPIO_Port GPIOB
#define INT_LED5_Pin GPIO_PIN_9
#define INT_LED5_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
int spin_motor(int, int);
void lock_check();
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
