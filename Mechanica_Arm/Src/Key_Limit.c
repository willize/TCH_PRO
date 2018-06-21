#include "Key_Limit.h"
#include "TIM.h"
#include "main.h"
#include "delay.h"
#include "Motor_Control.h"

extern u8 X_TI_stuta;
extern u8 Y_TI_stuta;
extern u8 Z_TI_stuta;
u8 X_Lim_L=0;
u8 X_Lim_R=0;
u8 Y_Lim_L=0;
u8 Y_Lim_R=0;
u8 Z_Lim_UP=0;
u8 Z_Lim_D=0;

//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//{
//	    switch(GPIO_Pin)  
//    {  
//        case GPIO_PIN_7:  //x左方向
//				
//					HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1);
//					HAL_TIM_Base_Stop_IT(&htim4);
//				 
//				  delay_ms(20);
//					X_R_MOV();
//				  x_Set_speed(7000);				  
//					HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
//				  delay_ms(500);
//				  HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1);
//				  //X_TI_stuta=0x01;
//					//printf("X_R_LIM\r\n");
//					break;
//							
//        case GPIO_PIN_8:  //X右方向 原点
//				
//					HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1);
//					HAL_TIM_Base_Stop_IT(&htim4);
//				
//					delay_ms(20);
//					X_L_MOV();
//				  x_Set_speed(7000);				  
//					HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
//					printf("X_R_LIM\r\n");
//				  delay_ms(500);
//				  HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1);
//				  X_TI_stuta=0x0001;
//					printf("X_R_LIM\r\n");
//				  
//				  break;
//				  
//        case GPIO_PIN_9:   //Y轴左  原点
//					HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
//					HAL_TIM_Base_Stop_IT(&htim3);
//				
//					delay_ms(20);
//					Y_R_MOV();
//				  y_Set_speed(7000);				  
//					HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
//				  delay_ms(500);
//				  HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
//				  Y_TI_stuta=0x0001;
//				
//				  printf("Y_L_LIM\r\n");
//					break;
//									
//        case GPIO_PIN_10:
//					HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
//					HAL_TIM_Base_Stop_IT(&htim3);
//				
//					delay_ms(20);
//					Y_L_MOV();
//				  y_Set_speed(7000);				  
//					HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
//				  delay_ms(500);
//				  HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
//				 // Y_TI_stuta=0x01;
//				
//					break;
//								
//				case GPIO_PIN_11:
//					HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
//					HAL_TIM_Base_Stop_IT(&htim2);
//				
//					delay_ms(200);
//					Z_DOWN_MOV();
//				  z_Set_speed(2500);				  
//					HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
//				  delay_ms(500);
//				  HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
//				  Z_TI_stuta=0x0001;	

//					printf("Z_UP_LIM\r\n");				
//						break;
//						
//				case GPIO_PIN_12:
//					HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
//        HAL_TIM_Base_Stop_IT(&htim2);
//					
//				delay_ms(200);
//				Z_UP_MOV();
//				z_Set_speed(2500);				  
//				HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
//				delay_ms(500);
//				HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
//							
//				
//				
//					break;
//													
//        default:
//				
//					
//					break;
//				 				
//    }  	
//}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	switch(GPIO_Pin)  
    {  
        case GPIO_PIN_7:  //x左方向
					if (X_Lim_L==0)
					{
						X_Lim_L=1;
						HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1);
						HAL_TIM_Base_Stop_IT(&htim4);
					}
				break;
				
				case GPIO_PIN_8://x原点
					if (X_Lim_R==0)
					{
						X_Lim_R=1;
						HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1);
						HAL_TIM_Base_Stop_IT(&htim4);
					}
				break;
				
				case GPIO_PIN_9: //Y轴原点
					if (Y_Lim_L==0)
					{
						Y_Lim_L=1;
						HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
						HAL_TIM_Base_Stop_IT(&htim3);
					}
				break;
				
				case GPIO_PIN_10:
					if (Y_Lim_R==0)
					{
						Y_Lim_R=1;
						HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
						HAL_TIM_Base_Stop_IT(&htim3);
					}
				break;
				
				case GPIO_PIN_11://z轴原点
					if (Z_Lim_UP==0)
					{
						Z_Lim_UP=1;
						HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
						HAL_TIM_Base_Stop_IT(&htim2);
					}
				break;
				
				case GPIO_PIN_12:
					if (Z_Lim_D==0)
					{
						Z_Lim_D=1;
						HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
						HAL_TIM_Base_Stop_IT(&htim2);
					}
				break;	
				default:
					
				break;
		}
}


void Limit_control()
{
	if (X_Lim_L==1)
	{
		delay_ms(500);
		X_R_MOV();
		x_Set_speed(7000);				  
		HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
		delay_ms(500);
		HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1);
		X_Lim_L=0;
	}
	if (X_Lim_R==1)
	{
		delay_ms(500);
		X_L_MOV();
		x_Set_speed(7000);				  
		HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
		delay_ms(500);
		HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1);
		X_TI_stuta = 0x0001;
		X_Lim_R=0;
	}
	if (Y_Lim_L==1)
	{
		delay_ms(500);
		Y_R_MOV();
		y_Set_speed(7000);				  
		HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
		delay_ms(500);
		HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
		Y_TI_stuta = 0x0001;
		Y_Lim_L=0;
	}
	if (Y_Lim_R==1)
	{
		delay_ms(500);
		Y_L_MOV();
		y_Set_speed(7000);				  
		HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
		delay_ms(500);
		HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
		Y_Lim_R=0;
	}
	if (Z_Lim_UP==1)
	{
		delay_ms(500);
		Z_DOWN_MOV();
		z_Set_speed(2500);
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
		delay_ms(500);
		HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
		Z_TI_stuta=0x0001;
		Z_Lim_UP=0;
	}
		if (Z_Lim_D==1)
	{
		delay_ms(500);
		Z_UP_MOV();
		z_Set_speed(2500);
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
		delay_ms(500);
		HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
		Z_Lim_D=0;
	}
	
}




