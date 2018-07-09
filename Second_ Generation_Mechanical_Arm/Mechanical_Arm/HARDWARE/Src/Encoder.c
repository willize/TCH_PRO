#include "Encoder.h"
#include "main.h"


TIM_HandleTypeDef TIM2_Handler;      //X定时器句柄  //编码器定时器
TIM_HandleTypeDef TIM3_Handler;      //定时器句柄 
TIM_HandleTypeDef TIM5_Handler;      //定时器句柄 
TIM_Encoder_InitTypeDef  X_Encoder;
TIM_Encoder_InitTypeDef  Y_Encoder;
TIM_Encoder_InitTypeDef  Z_Encoder;

void X_Encoder_Init(u16 arr,u16 psc)
{  
    TIM2_Handler.Instance=TIM2;                          //通用定时器3
    TIM2_Handler.Init.Prescaler=psc;                     //分频系数
    TIM2_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;    //向上计数器
    TIM2_Handler.Init.Period=arr;                        //自动装载值
    TIM2_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//时钟分频因子
    HAL_TIM_Base_Init(&TIM2_Handler);
	
   // HAL_TIM_Base_Start_IT(&TIM3_Handler); //使能定时器3和定时器3更新中断：TIM_IT_UPDATE   

  X_Encoder.EncoderMode        = TIM_ENCODERMODE_TI1;  
  X_Encoder.IC1Polarity        = TIM_ICPOLARITY_RISING;   
  X_Encoder.IC1Selection       = TIM_ICSELECTION_DIRECTTI;  
  X_Encoder.IC1Prescaler       = TIM_ICPSC_DIV1; 
	X_Encoder.IC1Filter          = 0;
  
  X_Encoder.IC2Polarity        = TIM_ICPOLARITY_RISING;   
	X_Encoder.IC2Selection       = TIM_ICSELECTION_DIRECTTI;  
  X_Encoder.IC2Prescaler       = TIM_ICPSC_DIV1; 
  X_Encoder.IC2Filter          = 0;
  HAL_TIM_Encoder_Init(&TIM2_Handler, &X_Encoder);
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

  Y_Encoder.EncoderMode        = TIM_ENCODERMODE_TI1;  
  Y_Encoder.IC1Polarity        = TIM_ICPOLARITY_RISING;   
  Y_Encoder.IC1Selection       = TIM_ICSELECTION_DIRECTTI;  
  Y_Encoder.IC1Prescaler       = TIM_ICPSC_DIV1; 
	Y_Encoder.IC1Filter          = 0;
  
  Y_Encoder.IC2Polarity        = TIM_ICPOLARITY_RISING;   
  Y_Encoder.IC2Selection       = TIM_ICSELECTION_DIRECTTI;  
  Y_Encoder.IC2Prescaler       = TIM_ICPSC_DIV1; 
  Y_Encoder.IC2Filter          = 0;
  HAL_TIM_Encoder_Init(&TIM3_Handler, &Y_Encoder);
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

		Z_Encoder.EncoderMode        = TIM_ENCODERMODE_TI1;  
		Z_Encoder.IC1Polarity        = TIM_ICPOLARITY_RISING;   
		Z_Encoder.IC1Selection       = TIM_ICSELECTION_DIRECTTI;  
		Z_Encoder.IC1Prescaler       = TIM_ICPSC_DIV1; 
		Z_Encoder.IC1Filter          = 0;
		
		Z_Encoder.IC2Polarity        = TIM_ICPOLARITY_RISING;   
		Z_Encoder.IC2Selection       = TIM_ICSELECTION_DIRECTTI;  
		Z_Encoder.IC2Prescaler       = TIM_ICPSC_DIV1; 
		Z_Encoder.IC2Filter          = 0;
		HAL_TIM_Encoder_Init(&TIM5_Handler, &Z_Encoder);
}


void HAL_TIM_Encoder_MspInit(TIM_HandleTypeDef *htim)
{
	 GPIO_InitTypeDef GPIO_InitStruct;
	if ( htim->Instance == TIM2)
	{
		__HAL_RCC_TIM2_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_GPIOB_CLK_ENABLE();

		    /* ?????1????IO??? */
    GPIO_InitStruct.Pin = X_ENCODER_1_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull=GPIO_PULLUP;
		 GPIO_InitStruct.Alternate=GPIO_AF1_TIM2;
    HAL_GPIO_Init(X_ENCODER_1_GPIO, &GPIO_InitStruct);
		
		GPIO_InitStruct.Pin = X_ENCODER_2_PIN;
		GPIO_InitStruct.Alternate=GPIO_AF1_TIM2;
		HAL_GPIO_Init(X_ENCODER_2_GPIO, &GPIO_InitStruct);
		
		HAL_NVIC_SetPriority(TIM2_IRQn,0,1);
		HAL_NVIC_EnableIRQ(TIM2_IRQn);
		
		TIM2->CNT=0;
	}
	if ( htim->Instance == TIM3)
	{
		__HAL_RCC_TIM3_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
		
		    /* ?????1????IO??? */
    GPIO_InitStruct.Pin = Y_ENCODER_1_PIN |Y_ENCODER_2_PIN ;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull=GPIO_PULLUP;
		 GPIO_InitStruct.Alternate=GPIO_AF2_TIM3;
    HAL_GPIO_Init(Y_ENCODER_1_GPIO, &GPIO_InitStruct);
		
		HAL_NVIC_SetPriority(TIM3_IRQn,0,2);
		HAL_NVIC_EnableIRQ(TIM3_IRQn);
		
		TIM3->CNT=0;
	}
		
	if ( htim->Instance == TIM5)
	{
		__HAL_RCC_TIM5_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
		
		    /* ?????1????IO??? */
    GPIO_InitStruct.Pin = Z_ENCODER_1_PIN|Z_ENCODER_2_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull=GPIO_PULLUP;
		 GPIO_InitStruct.Alternate=GPIO_AF2_TIM3;
    HAL_GPIO_Init(Z_ENCODER_1_GPIO, &GPIO_InitStruct);
		
		HAL_NVIC_SetPriority(TIM3_IRQn,0,3);
		HAL_NVIC_EnableIRQ(TIM3_IRQn);
		
		TIM3->CNT=0;	
	}
}

void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&TIM2_Handler);
}

void TIM3_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&TIM3_Handler);
}
void TIM5_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&TIM5_Handler);
}


