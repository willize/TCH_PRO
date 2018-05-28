/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */
#include "stm32f4xx_hal.h"
/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define G_key_Pin GPIO_PIN_2
#define G_key_GPIO_Port GPIOE
#define B_key_Pin GPIO_PIN_5
#define B_key_GPIO_Port GPIOE
#define R_key_Pin GPIO_PIN_6
#define R_key_GPIO_Port GPIOE
#define Air_Open_Pin GPIO_PIN_0
#define Air_Open_GPIO_Port GPIOC
#define Air_Close_Pin GPIO_PIN_1
#define Air_Close_GPIO_Port GPIOC
#define Step_motor_Z_Pin GPIO_PIN_1
#define Step_motor_Z_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_6
#define LED1_GPIO_Port GPIOA
#define LED2_Pin GPIO_PIN_7
#define LED2_GPIO_Port GPIOA
#define X_L_Limit_Pin GPIO_PIN_7
#define X_L_Limit_GPIO_Port GPIOE
#define X_R_Limit_Pin GPIO_PIN_8
#define X_R_Limit_GPIO_Port GPIOE
#define Y_L_Limit_Pin GPIO_PIN_9
#define Y_L_Limit_GPIO_Port GPIOE
#define Y_R_Limit_Pin GPIO_PIN_10
#define Y_R_Limit_GPIO_Port GPIOE
#define Z_Up_Limit_Pin GPIO_PIN_11
#define Z_Up_Limit_GPIO_Port GPIOE
#define Z_D_Limit_Pin GPIO_PIN_12
#define Z_D_Limit_GPIO_Port GPIOE
#define Step_motor_X_Pin GPIO_PIN_12
#define Step_motor_X_GPIO_Port GPIOD
#define Step_motor_Y_Pin GPIO_PIN_6
#define Step_motor_Y_GPIO_Port GPIOC
#define USART1_Tx_Pin GPIO_PIN_9
#define USART1_Tx_GPIO_Port GPIOA
#define USART1_Rx_Pin GPIO_PIN_10
#define USART1_Rx_GPIO_Port GPIOA
#define Z_Dir_Pin GPIO_PIN_3
#define Z_Dir_GPIO_Port GPIOB
#define Z_En_Pin GPIO_PIN_5
#define Z_En_GPIO_Port GPIOB
#define X_Dir_Pin GPIO_PIN_6
#define X_Dir_GPIO_Port GPIOB
#define X_En_Pin GPIO_PIN_7
#define X_En_GPIO_Port GPIOB
#define Y_Dir_Pin GPIO_PIN_8
#define Y_Dir_GPIO_Port GPIOB
#define Y_En_Pin GPIO_PIN_9
#define Y_En_GPIO_Port GPIOB

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
