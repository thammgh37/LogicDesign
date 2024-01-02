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
#include "input.h"
#include "fsm_system.h"
#include "software_timer.h"
#include "global.h"
#include "display.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
extern TIM_HandleTypeDef htim2;
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void display7SEG(int num);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define EN2_Pin GPIO_PIN_9
#define EN2_GPIO_Port GPIOB
#define D_Pin GPIO_PIN_4
#define D_GPIO_Port GPIOB
#define B_Pin GPIO_PIN_3
#define B_GPIO_Port GPIOB
#define EN3_Pin GPIO_PIN_8
#define EN3_GPIO_Port GPIOB
#define E_Pin GPIO_PIN_5
#define E_GPIO_Port GPIOB
#define F_Pin GPIO_PIN_10
#define F_GPIO_Port GPIOA
#define G_Pin GPIO_PIN_8
#define G_GPIO_Port GPIOA
#define MODE2_Pin GPIO_PIN_1
#define MODE2_GPIO_Port GPIOC
#define MODE3_Pin GPIO_PIN_0
#define MODE3_GPIO_Port GPIOC
#define A_Pin GPIO_PIN_2
#define A_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_5
#define EN1_GPIO_Port GPIOA
#define MODE1_Pin GPIO_PIN_0
#define MODE1_GPIO_Port GPIOB
#define BUTTON1_Pin GPIO_PIN_0
#define BUTTON1_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_3
#define LED_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_6
#define EN0_GPIO_Port GPIOA
#define C_Pin GPIO_PIN_10
#define C_GPIO_Port GPIOB
#define BUTTON2_Pin GPIO_PIN_1
#define BUTTON2_GPIO_Port GPIOA
#define BUTTON3_Pin GPIO_PIN_4
#define BUTTON3_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
