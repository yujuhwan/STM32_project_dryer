/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

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
#define GPIO_LED_Pin GPIO_PIN_13
#define GPIO_LED_GPIO_Port GPIOC
#define GPIO_SW_Pin GPIO_PIN_0
#define GPIO_SW_GPIO_Port GPIOA
#define PA2_TEMP_DATA_Pin GPIO_PIN_2
#define PA2_TEMP_DATA_GPIO_Port GPIOA
#define PA3_TEMP_DATA_Pin GPIO_PIN_3
#define PA3_TEMP_DATA_GPIO_Port GPIOA
#define PB0_TEMP_SET_UP_Pin GPIO_PIN_0
#define PB0_TEMP_SET_UP_GPIO_Port GPIOB
#define PB0_TEMP_SET_UP_EXTI_IRQn EXTI0_IRQn
#define PB1_TEMP_SET_FIX_Pin GPIO_PIN_1
#define PB1_TEMP_SET_FIX_GPIO_Port GPIOB
#define PB1_TEMP_SET_FIX_EXTI_IRQn EXTI1_IRQn
#define PB2_TEMP_SET_DOWN_Pin GPIO_PIN_2
#define PB2_TEMP_SET_DOWN_GPIO_Port GPIOB
#define PB2_TEMP_SET_DOWN_EXTI_IRQn EXTI2_IRQn
#define PB12_START_SW_PIN_GPIO_Port_Pin GPIO_PIN_12
#define PB12_START_SW_PIN_GPIO_Port_GPIO_Port GPIOB
#define FND_SCLK_Pin GPIO_PIN_13
#define FND_SCLK_GPIO_Port GPIOB
#define FND_RCLK_Pin GPIO_PIN_14
#define FND_RCLK_GPIO_Port GPIOB
#define FND_DIO_Pin GPIO_PIN_15
#define FND_DIO_GPIO_Port GPIOB
#define PB5_RELAY_ON_OFF_CTRL_Pin GPIO_PIN_5
#define PB5_RELAY_ON_OFF_CTRL_GPIO_Port GPIOB
#define PB6_LED1_Pin GPIO_PIN_6
#define PB6_LED1_GPIO_Port GPIOB
#define PB7_LED1_Pin GPIO_PIN_7
#define PB7_LED1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
