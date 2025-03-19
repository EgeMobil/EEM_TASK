/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdarg.h> // Eksik başlık dosyası eklendi
#include <stdio.h>  // vsnprintf için gerekli
#include <string.h> // memset için gerekli
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
#define SERIAL_UART_ADDR      &huart1

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void serial_message(const char *serial_data, ...);
extern uint32_t intervalLastTick;
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MCU_USER_LED_GREEN_Pin GPIO_PIN_12
#define MCU_USER_LED_GREEN_GPIO_Port GPIOD
#define MCU_USER_LED_ORANGE_Pin GPIO_PIN_13
#define MCU_USER_LED_ORANGE_GPIO_Port GPIOD
#define MCU_USER_LED_RED_Pin GPIO_PIN_14
#define MCU_USER_LED_RED_GPIO_Port GPIOD
#define MCU_USER_LED_BLUE_Pin GPIO_PIN_15
#define MCU_USER_LED_BLUE_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
