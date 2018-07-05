#include "IT.h"
#include "Motor.h"
extern TIM_HandleTypeDef htim10;
extern TIM_HandleTypeDef htim11;
extern TIM_HandleTypeDef htim13;

extern float Z_Accel_Freq[1000],XY_Accel_Freq[100];
extern u16   Z_Accel_Period[1000],XY_Accel_Period[100];

extern volatile u16 X_IT_Num, Y_IT_Num, Z_IT_Num;  //需要中断的次数
u16 Z_Num,YNum,X_Num;                              //记录当前中断次数
u16 X_Decel_Num,Y_Decel_Num,Z_Decel_Num;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance==htim10)
	{
		X_Num++;
		/*-----------调试阶段--------------*/
		if (Teach_Status_flag)
		{
			if (X_IT_Num == X_Num)
			{
				X_Num = 0;
				X_Stop();
			}
		}
		/*----------运行阶段--------------*/
		else if(Run_status_flag)
		{
			if (X_Num <= 100 )
			{
				X_Set_Autorelaod( XY_Accel_Freq[ X_Num-1])
			}
			else if (X_Num >= (X_IT_Num - 100) && X_Num < X_IT_Num)
					{
						X_Decel_Num--;
						X_Set_AutoReload( XY_Accel_Freq[ X_Decel_Num ]);
						if (X_Decel_Num == 0)X_Decel_Num = 100;
					}
			       else if(X_Num >= X_IT_Num)
						 {
							 X_Num = 0;
							 X_Stop();
						 }
		 }
		
		
		
	}
	
	
	
}