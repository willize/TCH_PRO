#include "Encode.h"

TIM_HandleTypeDef TIM2_Handler;      //X定时器句柄  //编码器定时器
TIM_HandleTypeDef TIM3_Handler;      //定时器句柄 
TIM_HandleTypeDef TIM5_Handler;      //定时器句柄 


void X_Encoder_Init(u16 arr,u16 psc)
{  
    TIM2_Handler.Instance=TIM2;                          //通用定时器3
    TIM2_Handler.Init.Prescaler=psc;                     //分频系数
    TIM2_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;    //向上计数器
    TIM2_Handler.Init.Period=arr;                        //自动装载值
    TIM2_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//时钟分频因子
    HAL_TIM_Base_Init(&TIM2_Handler);
	
   // HAL_TIM_Base_Start_IT(&TIM3_Handler); //使能定时器3和定时器3更新中断：TIM_IT_UPDATE   

  TIM2_Handler.EncoderMode        = TIM_ENCODERMODE_TI1;  
  TIM2_Handler.IC1Polarity        = TIM_ICPOLARITY_RISING;   
  TIM2_Handler.IC1Selection       = TIM_ICSELECTION_DIRECTTI;  
  TIM2_Handler.IC1Prescaler       = TIM_ICPSC_DIV1; 
	TIM2_Handler.IC1Filter          = 0;
  
  TIM2_Handler.IC2Polarity        = TIM_ICPOLARITY_RISING;   
  TIM2_Handler.IC2Selection       = TIM_ICSELECTION_DIRECTTI;  
  TIM2_Handler.IC2Prescaler       = TIM_ICPSC_DIV1; 
  TIM2_Handler.IC2Filter          = 0;
  HAL_TIM_Encoder_Init(&htimx_Encoder, &TIM2_Handler);
}

void Y_Encoder_Init(u16 arr,u16 psc)
{  
    TIM3_Handler.Instance=TIM3;                          //通用定时器3
    TIM3_Handler.Init.Prescaler=psc;                     //分频系数
    TIM3_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;    //向上计数器
    TIM3_Handler.Init.Period=arr;                        //自动装载值
    TIM3_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//时钟分频因子
    HAL_TIM_Base_Init(&TIM3_Handler);
	
   // HAL_TIM_Base_Start_IT(&TIM3_Handler); //使能定时器3和定时器3更新中断：TIM_IT_UPDATE   

  TIM3_Handler.EncoderMode        = TIM_ENCODERMODE_TI1;  
  TIM3_Handler.IC1Polarity        = TIM_ICPOLARITY_RISING;   
  TIM3_Handler.IC1Selection       = TIM_ICSELECTION_DIRECTTI;  
  TIM3_Handler.IC1Prescaler       = TIM_ICPSC_DIV1; 
	TIM3_Handler.IC1Filter          = 0;
  
  TIM3_Handler.IC2Polarity        = TIM_ICPOLARITY_RISING;   
  TIM3_Handler.IC2Selection       = TIM_ICSELECTION_DIRECTTI;  
  TIM3_Handler.IC2Prescaler       = TIM_ICPSC_DIV1; 
  TIM3_Handler.IC2Filter          = 0;
  HAL_TIM_Encoder_Init(&htimx_Encoder, &TIM3_Handler);
}


void Z_Encoder_Init(u16 arr,u16 psc)
{  
    TIM5_Handler.Instance=TIM5;                          //通用定时器3
    TIM5_Handler.Init.Prescaler=psc;                     //分频系数
    TIM5_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;    //向上计数器
    TIM5_Handler.Init.Period=arr;                        //自动装载值
    TIM5_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//时钟分频因子
    HAL_TIM_Base_Init(&TIM5_Handler);
	
   // HAL_TIM_Base_Start_IT(&TIM3_Handler); //使能定时器3和定时器3更新中断：TIM_IT_UPDATE   

		TIM5_Handler.EncoderMode        = TIM_ENCODERMODE_TI1;  
		TIM5_Handler.IC1Polarity        = TIM_ICPOLARITY_RISING;   
		TIM5_Handler.IC1Selection       = TIM_ICSELECTION_DIRECTTI;  
		TIM5_Handler.IC1Prescaler       = TIM_ICPSC_DIV1; 
		TIM5_Handler.IC1Filter          = 0;
		
		TIM5_Handler.IC2Polarity        = TIM_ICPOLARITY_RISING;   
		TIM5_Handler.IC2Selection       = TIM_ICSELECTION_DIRECTTI;  
		TIM5_Handler.IC2Prescaler       = TIM_ICPSC_DIV1; 
		TIM5_Handler.IC2Filter          = 0;
		HAL_TIM_Encoder_Init(&htimx_Encoder, &TIM5_Handler);
}


void HAL_TIM_Encoder_MspInit(TIM_HandleTypeDef *htim)
{
	 GPIO_InitTypeDef GPIO_Initure;
	if ( htim->Instance == TIM2)
	{
		__HAL_RCC_TIM2_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_GPIOB_CLK_ENABLE();
		    /* ?????1????IO??? */
    GPIO_InitStruct.Pin = GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull=GPIO_PULLUP;
		 GPIO_InitStruct.Alternate=GPIO_AF2_TIM2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		
		GPIO_InitStruct.Pin = GPIO_PIN_3;
		GPIO_InitStruct.Alternate=GPIO_AF2_TIM2;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		
		HAL_NVIC_SetPriority(TIM2_IROn,0,3);
		HAL_NVIC_Enable(TIM2_IRQn);
		
		TIM2->CNT=0;
	}
	if ( htim->Instance == TIM3)
	{
		__HAL_RCC_TIM3_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
		
		    /* ?????1????IO??? */
    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull=GPIO_PULLUP;
		 GPIO_InitStruct.Alternate=GPIO_AF2_TIM3;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
		
		HAL_NVIC_SetPriority(TIM3_IROn,0,2);
		HAL_NVIC_Enable(TIM3_IRQn);
		
		TIM3->CNT=0;
		
	if ( htim->Instance == TIM5)
	{
		__HAL_RCC_TIM3_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
		
		    /* ?????1????IO??? */
    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull=GPIO_PULLUP;
		 GPIO_InitStruct.Alternate=GPIO_AF2_TIM3;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
		
		HAL_NVIC_SetPriority(TIM3_IROn,0,2);
		HAL_NVIC_Enable(TIM3_IRQn);
		
		TIM3->CNT=0;	
	}
}

void TIM3_IRQHandler(void)
{
	HAL_TIM_IRQHander(&TIM3_Handler)
}
