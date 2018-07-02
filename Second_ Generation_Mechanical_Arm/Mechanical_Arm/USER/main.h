/**
  ******************************************************************************
  * @file    Templates/Inc/main.h 
  * @author  MCD Application Team
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
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
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/


/*--------------------------------编码器--------------------------------------*/
#define X_ENCODER_1_PIN GPIO_PIN_15
#define X_ENCODER_1_GPIO   GPIOA
#define X_ENCODER_2_PIN GPIO_PIN_3
#define X_ENCODER_2_GPIO   GPIOB

#define Y_ENCODER_1_PIN GPIO_PIN_6
#define Y_ENCODER_1_GPIO   GPIOC
#define Y_ENCODER_2_PIN GPIO_PIN_7
#define Y_ENCODER_2_GPIO   GPIOC

#define Z_ENCODER_1_PIN GPIO_PIN_0
#define Z_ENCODER_1_GPIO   GPIOA
#define Z_ENCODER_2_PIN GPIO_PIN_1
#define Z_ENCODER_2_GPIO   GPIOA
/******************************************************************************/

/*----------------------------各轴电机的PWM通道-------------------------------*/
#define X_PWM_PIN GPIO_PIN_6
#define X_PWM_GPIO   GPIOF

#define Y_PWM_PIN GPIO_PIN_7
#define Y_PWM_GPIO   GPIOF

#define Z_PWM_PIN GPIO_PIN_8
#define Z_PWM_GPIO   GPIOF
/******************************************************************************/

/*---------------------------TIM4-PWM波形产生通道------------------------------*/
#define PWM_1_PIN  GPIO_PIN_12
#define PWM_1_GPIO GPIOD
#define PWM_2_PIN  GPIO_PIN_13
#define PWM_2_GPIO GPIOD
#define PWM_3_PIN  GPIO_PIN_14
#define PWM_3_GPIO GPIOD
#define PWM_4_PIN  GPIO_PIN_15
#define PWM_4_GPIO GPIOD
/******************************************************************************/

/*-----------------------------电机方向---------------------------------------*/
#define X_DIR_PIN  GPIO_PIN_9
#define X_DIR_GPIO GPIOD

#define Y_DIR_PIN  GPIO_PIN_10
#define Y_DIR_GPIO GPIOD

#define Z_DIR_PIN  GPIO_PIN_11
#define Z_DIR_GPIO GPIOD
/******************************************************************************/

/*------------------------------USART-----------------------------------------*/
#define USART1_TX_PIN  GPIO_PIN_9
#define USART1_TX_GPIO GPIOA
#define USART1_RX_PIN  GPIO_PIN_10
#define USART1_RX_GPIO GPIOA

#define USART2_TX_PIN  GPIO_PIN_2
#define USART2_TX_GPIO GPIOA
#define USART2_RX_PIN  GPIO_PIN_3
#define USART2_RX_GPIO GPIOA

#define USART3_TX_PIN  GPIO_PIN_10
#define USART3_TX_GPIO GPIOB
#define USART3_RX_PIN  GPIO_PIN_11
#define USART3_RX_GPIO GPIOB
/******************************************************************************/

/*---------------------------------SPI----------------------------------------*/
#define SPI1_SCK_PIN   GPIO_PIN_5
#define SPI1_SCK_GPIO  GPIOA
#define SPI1_MISO_PIN   GPIO_PIN_6
#define SPI1_MISO_GPIO  GPIOA
#define SPI1_MOSI_PIN   GPIO_PIN_7
#define SPI1_MOSI_GPIO  GPIOA

#define SPI2_SCK_PIN   GPIO_PIN_13
#define SPI2_SCK_GPIO  GPIOB
#define SPI2_MISO_PIN   GPIO_PIN_2
#define SPI2_MISO_GPIO  GPIOC
#define SPI2_MOSI_PIN   GPIO_PIN_3
#define SPI2_MOSI_GPIO  GPIOC
/******************************************************************************/
/*------------------------------------Limit-----------------------------------*/
#define X_L_LIMIT_PIN   GPIO_PIN_0
#define X_L_LIMIT_GPIO  GPIOD
#define X_R_LIMIT_PIN   GPIO_PIN_1
#define X_R_LIMIT_GPIO  GPIOD

#define Y_L_LIMIT_PIN   GPIO_PIN_2
#define Y_L_LIMIT_GPIO    GPIOD
#define Y_R_LIMIT_PIN   GPIO_PIN_3
#define Y_R_LIMIT_GPIO  GPIOD

#define Z_UP_LIMIT_PIN     GPIO_PIN_4
#define Z_UP_LIMIT_GPIO    GPIOD
#define Z_DOWN_LIMIT_PIN   GPIO_PIN_5
#define Z_DOWN_LIMIT_GPIO  GPIOD

/******************************************************************************/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */







#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
