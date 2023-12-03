/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#define BUTTON_CHANGE_Pin GPIO_PIN_0
#define BUTTON_CHANGE_GPIO_Port GPIOC
#define BUTTON_MODE_Pin GPIO_PIN_1
#define BUTTON_MODE_GPIO_Port GPIOC
#define LED_NORMAL_MODE_Pin GPIO_PIN_1
#define LED_NORMAL_MODE_GPIO_Port GPIOA
#define ROW1_Pin GPIO_PIN_2
#define ROW1_GPIO_Port GPIOA
#define ROW0_Pin GPIO_PIN_3
#define ROW0_GPIO_Port GPIOA
#define LED_CHAR_MODE_Pin GPIO_PIN_4
#define LED_CHAR_MODE_GPIO_Port GPIOA
#define ENM5_Pin GPIO_PIN_5
#define ENM5_GPIO_Port GPIOA
#define ENM4_Pin GPIO_PIN_6
#define ENM4_GPIO_Port GPIOA
#define ENM3_Pin GPIO_PIN_7
#define ENM3_GPIO_Port GPIOA
#define LED_ANI_MODE_Pin GPIO_PIN_0
#define LED_ANI_MODE_GPIO_Port GPIOB
#define ROW6_Pin GPIO_PIN_10
#define ROW6_GPIO_Port GPIOB
#define ENM1_Pin GPIO_PIN_7
#define ENM1_GPIO_Port GPIOC
#define ROW7_Pin GPIO_PIN_8
#define ROW7_GPIO_Port GPIOA
#define ENM0_Pin GPIO_PIN_9
#define ENM0_GPIO_Port GPIOA
#define ROW2_Pin GPIO_PIN_10
#define ROW2_GPIO_Port GPIOA
#define ROW3_Pin GPIO_PIN_3
#define ROW3_GPIO_Port GPIOB
#define ROW5_Pin GPIO_PIN_4
#define ROW5_GPIO_Port GPIOB
#define ROW4_Pin GPIO_PIN_5
#define ROW4_GPIO_Port GPIOB
#define ENM2_Pin GPIO_PIN_6
#define ENM2_GPIO_Port GPIOB
#define ENM7_Pin GPIO_PIN_8
#define ENM7_GPIO_Port GPIOB
#define ENM6_Pin GPIO_PIN_9
#define ENM6_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
