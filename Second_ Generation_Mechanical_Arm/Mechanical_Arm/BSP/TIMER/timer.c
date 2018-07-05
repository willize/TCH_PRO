#include "timer.h"
#include "led.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F429开发板
//定时器中断驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2016/1/6
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	


//TIM_HandleTypeDef TIM2_Handler;      //X定时器句柄  //编码器定时器
//TIM_HandleTypeDef TIM3_Handler;      //定时器句柄 
//TIM_HandleTypeDef TIM5_Handler;      //定时器句柄 

//TIM_HandleTypeDef TIM10_Handler;      //定时器句柄  //电机控制PWM波
//TIM_HandleTypeDef TIM11_Handler;      //定时器句柄 
//TIM_HandleTypeDef TIM13_Handler;      //定时器句柄 

//TIM_HandleTypeDef TIM4_Handler;      //定时器句柄   //PWM波输出4路输出通道

TIM_HandleTypeDef TIM6_Handler;      //定时器句柄   //滴答时钟，时间间隔
TIM_HandleTypeDef TIM7_Handler;      //定时器句柄 

//通用定时器3中断初始化
//arr：自动重装值。
//psc：时钟预分频数
//定时器溢出时间计算方法:Tout=((arr+1)*(psc+1))/Ft us.
///Ft=定时器工作频率,单位:Mhz
//这里使用的是定时器3!(定时器3挂在APB1上，时钟为HCLK/2)
void TIM6_Init(u16 arr,u16 psc)
{  
    TIM6_Handler.Instance=TIM3;                          //通用定时器3
    TIM6_Handler.Init.Prescaler=psc;                     //分频系数
    TIM6_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;    //向上计数器
    TIM6_Handler.Init.Period=arr;                        //自动装载值
    TIM6_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//时钟分频因子
    HAL_TIM_Base_Init(&TIM6_Handler);
	
    //HAL_TIM_Base_Start_IT(&TIM6_Handler); //使能定时器3和定时器3更新中断：TIM_IT_UPDATE   
}


void TIM7_Init(u16 arr,u16 psc)
{  
    TIM7_Handler.Instance=TIM7;                          //通用定时器3
    TIM7_Handler.Init.Prescaler=psc;                     //分频系数
    TIM7_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;    //向上计数器
    TIM7_Handler.Init.Period=arr;                        //自动装载值
    TIM7_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//时钟分频因子
    HAL_TIM_Base_Init(&TIM7_Handler);
	
    //HAL_TIM_Base_Start_IT(&TIM6_Handler); //使能定时器3和定时器3更新中断：TIM_IT_UPDATE   
}



//定时器底册驱动，开启时钟，设置中断优先级
//此函数会被HAL_TIM_Base_Init()函数调用
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
   if(htim->Instance==TIM6)
	{
		__HAL_RCC_TIM6_CLK_ENABLE();            //使能TIM3时钟
		HAL_NVIC_SetPriority(TIM6_DAC_IRQn,0,1);    //设置中断优先级，抢占优先级1，子优先级3
		HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);          //开启ITM3中断   
	}
	if (htim->Instance==TIM7) 
	{
		__HAL_RCC_TIM7_CLK_ENABLE();            //使能TIM3时钟
		HAL_NVIC_SetPriority(TIM7_IRQn,0,2);    //设置中断优先级，抢占优先级1，子优先级3
		HAL_NVIC_EnableIRQ(TIM7_IRQn);          //开启ITM3中断 		
	}
}


//定时器3中断服务函数
void TIM6_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&TIM6_Handler);
}


void TIM7_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&TIM7_Handler);
}


//回调函数，定时器中断服务函数调用
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim==(&TIM6_Handler))
    {
        
    }
		if(htim==(&TIM7_Handler))
    {
        
    }
}
