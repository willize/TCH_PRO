/**
  ******************************************************************************
  * @file    main.h 
  * @author  willize
  * @brief   Header for main.c module
  ******************************************************************************
  * 编码器为TIM2、3、5
  * 电机的PWM为TIM10、11、13 ， 4路的PWM为 TIM4 。
 	* 普通  整个系统的滴答时钟为TIM6、7
	*
	*
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/*-------------------机械臂最大移动速度---------------------------------------*/
#define  Z_MOTOR_SPEED   2  //r/s
#define XY_MOTOR_SPEED   1
/******************************************************************************/
/* Includes ------------------------------------------------------------------*/

#include "stm32f4xx_hal.h"

/* Exported types ------------------------------------------------------------*/
//TIM_HandleTypeDef TIM2_Handler;      //X定时器句柄  //编码器定时器
//TIM_HandleTypeDef TIM3_Handler;      //定时器句柄 
//TIM_HandleTypeDef TIM5_Handler;      //定时器句柄 

//TIM_HandleTypeDef TIM10_Handler;      //定时器句柄  //电机控制PWM波
//TIM_HandleTypeDef TIM11_Handler;      //定时器句柄 
//TIM_HandleTypeDef TIM13_Handler;      //定时器句柄 

//TIM_HandleTypeDef TIM4_Handler;      //定时器句柄   //PWM波输出4路输出通道

//TIM_HandleTypeDef TIM6_Handler;      //定时器句柄   //滴答时钟，时间间隔
//TIM_HandleTypeDef TIM7_Handler;      //定时器句柄 
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
#define X_PWM_PIN  GPIO_PIN_6
#define X_PWM_GPIO   GPIOF

#define Y_PWM_PIN  GPIO_PIN_7
#define Y_PWM_GPIO   GPIOF

#define Z_PWM_PIN  GPIO_PIN_8
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
void _Error_Handler(char *, int);






#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
