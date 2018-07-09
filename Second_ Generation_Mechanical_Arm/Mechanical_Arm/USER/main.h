/**
  ******************************************************************************
  * @file    main.h 
  * @author  willize
  * @brief   Header for main.c module
  ******************************************************************************
  * ������ΪTIM2��3��5
  * �����PWMΪTIM10��11��13 �� 4·��PWMΪ TIM4 ��
 	* ��ͨ  ����ϵͳ�ĵδ�ʱ��ΪTIM6��7
	*
	*
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/*-------------------��е������ƶ��ٶ�---------------------------------------*/
#define  Z_MOTOR_SPEED   2  //r/s
#define XY_MOTOR_SPEED   1
/******************************************************************************/
/* Includes ------------------------------------------------------------------*/

#include "stm32f4xx_hal.h"

/* Exported types ------------------------------------------------------------*/
//TIM_HandleTypeDef TIM2_Handler;      //X��ʱ�����  //��������ʱ��
//TIM_HandleTypeDef TIM3_Handler;      //��ʱ����� 
//TIM_HandleTypeDef TIM5_Handler;      //��ʱ����� 

//TIM_HandleTypeDef TIM10_Handler;      //��ʱ�����  //�������PWM��
//TIM_HandleTypeDef TIM11_Handler;      //��ʱ����� 
//TIM_HandleTypeDef TIM13_Handler;      //��ʱ����� 

//TIM_HandleTypeDef TIM4_Handler;      //��ʱ�����   //PWM�����4·���ͨ��

//TIM_HandleTypeDef TIM6_Handler;      //��ʱ�����   //�δ�ʱ�ӣ�ʱ����
//TIM_HandleTypeDef TIM7_Handler;      //��ʱ����� 
/* Exported constants --------------------------------------------------------*/


/*--------------------------------������--------------------------------------*/
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

/*----------------------------��������PWMͨ��-------------------------------*/
#define X_PWM_PIN  GPIO_PIN_6
#define X_PWM_GPIO   GPIOF

#define Y_PWM_PIN  GPIO_PIN_7
#define Y_PWM_GPIO   GPIOF

#define Z_PWM_PIN  GPIO_PIN_8
#define Z_PWM_GPIO   GPIOF
/******************************************************************************/

/*---------------------------TIM4-PWM���β���ͨ��------------------------------*/
#define PWM_1_PIN  GPIO_PIN_12
#define PWM_1_GPIO GPIOD
#define PWM_2_PIN  GPIO_PIN_13
#define PWM_2_GPIO GPIOD
#define PWM_3_PIN  GPIO_PIN_14
#define PWM_3_GPIO GPIOD
#define PWM_4_PIN  GPIO_PIN_15
#define PWM_4_GPIO GPIOD
/******************************************************************************/

/*-----------------------------�������---------------------------------------*/
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
