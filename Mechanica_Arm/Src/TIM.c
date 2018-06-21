#include "TIM.h"
#include "main.h"
#include "stm32f4xx_hal.h"
#include "Arm_Control.h"
#include "Motor_Control.h"


TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;
TIM_HandleTypeDef htim5;
TIM_HandleTypeDef htim6;
TIM_HandleTypeDef htim7;
TIM_HandleTypeDef htim12;


u16 Z_num5=0;
u16 Y_num6=0;
u16 X_num7=0;
u16 Z_Decel_Num = 1000;
u16 XY_Decel_Num = 50;
u16 Wait_time_s=0;

extern TI_num TIunm;

extern u16 X_TI_stuta;
extern u16 Y_TI_stuta;
extern u16 Z_TI_stuta;
extern u8 Z_downn_fla_1;
extern u8 Z_downn_fla_2;
extern u8 Z_downn_fla_3;
extern u8 Z_downn_point_1;
extern u8 Z_downn_point_2;
extern u8 Z_downn_point_3;

extern float Z_Accel_Freq	 [1000];
extern u16 	 Z_Accel_Period[1000];
extern float XY_Accel_Freq	 [50];
extern u16 	 XY_Accel_Period [50];
//extern float Decel_Freq	 [20];
//extern u16 	 Decel_Period[20];


void MX_TIM1_Init(void)
{

  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;

  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 83;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 1000;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 2;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM2 init function */
void MX_TIM2_Init(u16 pre, u16 arr )
{

  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;

  htim2.Instance = TIM2;
  htim2.Init.Prescaler = pre;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = arr;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = arr/2;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  HAL_TIM_MspPostInit(&htim2);

}

/* TIM3 init function */
void MX_TIM3_Init(u16 pre, u16 arr)
{

  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;

  htim3.Instance = TIM3;
  htim3.Init.Prescaler = pre;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = arr;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = arr/2;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  HAL_TIM_MspPostInit(&htim3);

}

/* TIM4 init function */
void MX_TIM4_Init(u16 pre, u16 arr)
{

  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;

  htim4.Instance = TIM4;
  htim4.Init.Prescaler = pre;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = arr;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_Init(&htim4) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = arr/2;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  HAL_TIM_MspPostInit(&htim4);

}

/* TIM5 init function */
void MX_TIM5_Init(u16 pre, u16 arr ) //Z轴定时
{ 

  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;

  htim5.Instance = TIM5;
  htim5.Init.Prescaler = pre;
  htim5.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim5.Init.Period = arr;
  htim5.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  if (HAL_TIM_Base_Init(&htim5) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim5, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim5, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM6 init function */
void MX_TIM6_Init(u16 pre, u16 arr)  //Y轴定时
{

  TIM_MasterConfigTypeDef sMasterConfig;

  htim6.Instance = TIM6;
  htim6.Init.Prescaler = pre;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = arr;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM7 init function */
void MX_TIM7_Init(u16 pre, u16 arr)  //Y轴定时
{

  TIM_MasterConfigTypeDef sMasterConfig;

  htim7.Instance = TIM7;
  htim7.Init.Prescaler = pre;
  htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim7.Init.Period = arr;
  if (HAL_TIM_Base_Init(&htim7) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim7, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM12 init function */
void MX_TIM12_Init(void)
{

  TIM_ClockConfigTypeDef sClockSourceConfig;

  htim12.Instance = TIM12;
  htim12.Init.Prescaler = 0;
  htim12.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim12.Init.Period = 0;
  htim12.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  if (HAL_TIM_Base_Init(&htim12) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim12, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}





void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance==TIM2)
	{	
			Z_num5++;
			if (Z_num5<=1000)
			{
				z_Set_speed( Z_Accel_Period[ Z_num5-1 ]);
			}
			if (Z_num5>=(TIunm.Z_TInum-1000) & Z_num5<TIunm.Z_TInum )
			{
				Z_Decel_Num--;
				z_Set_speed( Z_Accel_Period[ Z_Decel_Num ]);
				if (Z_Decel_Num==0)
				{
					Z_Decel_Num=1000;
				}
			}
			if (Z_num5>=TIunm.Z_TInum)
			{
			HAL_TIM_Base_Stop_IT(&htim2);
			HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
				
			Z_num5=0;
			if(Z_TI_stuta == 0x0001)
			{
				

				Z_TI_stuta=0x0002;	
				printf("Z_TIM5_TI\r\n");
				printf("Z_TI_stuta=%x ",Z_TI_stuta);
				Air_CLOSE();
			}
			else if ( Z_TI_stuta == 0x0002 )
			{
				Z_downn_fla_1=1;
				if(Z_downn_point_1==0)
				{
					Z_downn_fla_1=0;
					Z_downn_point_1=2;
					Z_TI_stuta=0x0004;	
				}
				
			}
			else if ( Z_TI_stuta == 0x0004 )
			{			
						Z_TI_stuta=0x0008;

					
			}
			else if ( Z_TI_stuta & 0x0008 )
			{
				Z_TI_stuta=0x0010;
			}
			else if ( Z_TI_stuta == 0x0010 )
			{
				Z_downn_fla_2 =1;
				if(Z_downn_point_2==0)
				{
					Z_downn_fla_2=0;
					Z_downn_point_2=2;
					Z_TI_stuta=0x0020;	
				}
			}
			else if ( Z_TI_stuta == 0x0020 ) {}
			else if ( Z_TI_stuta == 0x0040 ) {Z_TI_stuta=0x0080;}
			else if ( Z_TI_stuta == 0x0080 ) {Z_TI_stuta=0x0100;}
			else if ( Z_TI_stuta == 0x0100 ) {Z_TI_stuta=0x0200;}
			else if ( Z_TI_stuta == 0x0200 ) 
			{
				Z_downn_fla_3=1;
				if(Z_downn_point_3==0)
				{
					Z_downn_fla_3=0;
					Z_downn_point_3=2;
					Z_TI_stuta=0x0400;	
				}
			}
			else if ( Z_TI_stuta == 0x0400 ) {Z_TI_stuta=0x0800;}
			else if ( Z_TI_stuta == 0x0800 ) {Z_TI_stuta=0x1000;}
			else if ( Z_TI_stuta == 0x1000 ) {Z_TI_stuta=0x0001;}
			//else if ( Z_TI_stuta == 0x2000 ) {Z_TI_stuta=0x0002;}		
		}
	}
	
	if(htim->Instance==TIM3)
	{
			Y_num6++;
			if (Y_num6<=50)
			{
				y_Set_speed( XY_Accel_Period[ Y_num6- 1 ]);
			}
			if (Y_num6>=(TIunm.Y_TInum-50) & Y_num6<TIunm.Y_TInum )
			{
				XY_Decel_Num--;
				y_Set_speed( XY_Accel_Period[ XY_Decel_Num ]);
				if (XY_Decel_Num==0)
				{
					XY_Decel_Num=50;
				}
			}
		if (Y_num6>=TIunm.Y_TInum)
		{
				HAL_TIM_Base_Stop_IT(&htim3);
			  HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
				Y_num6=0;
			
			if (Y_TI_stuta & 0x0001)
			{
				HAL_TIM_Base_Stop_IT(&htim3);
			  HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
				Y_TI_stuta=0x0002;
				printf("Y_TIM6_TI_1\r\n");
				printf("Y_TI_stuta=%x",Y_TI_stuta);
			}
			else if ( Y_TI_stuta == 0x0002 ) 
			{	
				HAL_TIM_Base_Stop_IT(&htim3);
			  HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
				Y_TI_stuta=0x0004;
				printf("Y_TIM6_TI_2\r\n");
			}
			 else if ( Y_TI_stuta == 0x0004 )
			{
				HAL_TIM_Base_Stop_IT(&htim3);
			  HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
				Y_TI_stuta=0x0008;

				printf("Y_TIM6_TI_3\r\n");
			}
			else if (Y_TI_stuta & 0x0008)
			{
				Y_TI_stuta=0x0010;
				printf("Y_TIM6_TI_4\r\n");
			}
			else if ( Y_TI_stuta == 0x0010 ) {Y_TI_stuta=0x0020;}
			else if ( Y_TI_stuta == 0x0020 ) {}
			else if ( Y_TI_stuta == 0x0040 ) {Y_TI_stuta=0x0080;}
			else if ( Y_TI_stuta == 0x0080 ) {Y_TI_stuta=0x0100;}
			else if ( Y_TI_stuta == 0x0100 ) {Y_TI_stuta=0x0200;}
			else if ( Y_TI_stuta == 0x0200 ) {Y_TI_stuta=0x0400;}
			else if ( Y_TI_stuta == 0x0400 ) {Y_TI_stuta=0x0800;}
			else if ( Y_TI_stuta == 0x0800 ) {Y_TI_stuta=0x1000;}
			else if ( Y_TI_stuta == 0x1000 ) {Y_TI_stuta=0x0001;}
		//	else if ( Y_TI_stuta == 0x2000 ) {Y_TI_stuta=0x0002;}
			
		}
	}
	
	
	
	if(htim->Instance==TIM4)
	{
		X_num7++;
		if (X_num7<=50)
		{
			x_Set_speed( XY_Accel_Period[ X_num7 - 1 ]);
		}
		if (X_num7>=(TIunm.X_TInum-50) & X_num7<TIunm.X_TInum )
		{
			XY_Decel_Num--;
			x_Set_speed( XY_Accel_Period[ XY_Decel_Num ]);
			if (XY_Decel_Num==0)
			{
				XY_Decel_Num=50;
			}
		}

		if (X_num7>=TIunm.X_TInum)
		{
				HAL_TIM_Base_Stop_IT(&htim4);
			  HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1);

				X_num7=0;
			if(X_TI_stuta & 0x0001)
			{
				X_TI_stuta=0x0002;
				printf("X_TIM7_TI\r\n");
				printf("X_TI_stuta=%x",X_TI_stuta);
				Air_OPEN();
				
			} 
			else if (X_TI_stuta & 0x0002 ) 
			{

				X_TI_stuta=0x0004;
				
			}	
		  else if ( X_TI_stuta == 0x0004 )
			{

				X_TI_stuta=0x0008;
				
			}
			else if ( X_TI_stuta & 0x0008 )
			{

				X_TI_stuta=0x0010;
			}
			
			else if ( X_TI_stuta == 0x0010 ) {X_TI_stuta=0x0020;}
			else if ( X_TI_stuta == 0x0020 ) {}
			else if ( X_TI_stuta == 0x0040 ) {X_TI_stuta=0x0080;}
			else if ( X_TI_stuta == 0x0080 ) {X_TI_stuta=0x0100;}
			else if ( X_TI_stuta == 0x0100 ) {X_TI_stuta=0x0200;}
			else if ( X_TI_stuta == 0x0200 ) {X_TI_stuta=0x0400;}
			else if ( X_TI_stuta == 0x0400 ) {X_TI_stuta=0x0800;}
			else if ( X_TI_stuta == 0x0800 ) {X_TI_stuta=0x1000;}
			else if ( X_TI_stuta == 0x1000 ) {X_TI_stuta=0x0001;}
	//		else if ( X_TI_stuta == 0x2000 ) {X_TI_stuta=0x0002;}

			
			
		}
	}
	if(htim->Instance==TIM5)
	{
		Wait_time_s++;
		if (Wait_time_s==5) //  时间不能小于5秒，否则时间没到会更改Z_TI_statu的值
		{
			
			X_TI_stuta=0x0040;
			Y_TI_stuta=0x0040;
			Z_TI_stuta=0x0040;	
			Wait_time_s=0;
			HAL_TIM_Base_Stop_IT(&htim5);
			
		}
	}
	
}





