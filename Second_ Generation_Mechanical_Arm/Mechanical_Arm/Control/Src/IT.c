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

extern u8 mian_flag;                               //主控制函数运行点位的开关，保证每个点位的程序只运行一次。
extern u8 X_run_point,Y_run_point,Z_run_point;     //运行的点位。

 u8 X_IT_point, Y_IT_ponit, Z_IT_poit;             //运行到达，停止时中断的次数与运行点位对应。
 u8 max_run_point;                                 //最大的运行点数，应该由示教屏幕提供；

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

						 if ( X_IT_point == X_run_point )
						 {
							 if (max_run_point >= X_run_point)
							 X_run_point =0;
							 X_IT_point  =0;
							 main_flag =0;
							 else
							 X_run_point ++;
							 X_IT_point ++;
							 main_flag = 1;
						 }	 
					 }		 
		}	
	}


	if (htim->Instance==htim11)
	{
		Y_Num++;
		/*-----------调试阶段--------------*/
		if (Teach_Status_flag)
		{
			if (Y_IT_Num == Y_Num)
			{
				Y_Num = 0;
				Y_Stop();
			}
		}
		/*----------运行阶段--------------*/
		else if(Run_status_flag)
		{
			if (Y_Num <= 100 )
			{
				Y_Set_Autorelaod( XY_Accel_Freq[ X_Num-1])
			}
			else if (Y_Num >= (Y_IT_Num - 100) && Y_Num < Y_IT_Num)
					{
						Y_Decel_Num--;
						Y_Set_AutoReload( XY_Accel_Freq[ Y_Decel_Num ]);
						if (Y_Decel_Num == 0)Y_Decel_Num = 100;
					}
		  else if(Y_Num >= Y_IT_Num)
					 {
						 Y_Num = 0;
						 Y_Stop();

						 if ( Y_IT_point == Y_run_point )
						 {
							 if (max_run_point >= Y_run_point)
							 Y_run_point =1;
							 Y_IT_point  =1;
							 main_flag =1;
							 else
							 Y_run_point ++;
							 Y_IT_point ++;
							 main_flag = 1;
						 }	 
					 }		 
		}		
	}
	
	
		if (htim->Instance==htim13)
	{
		Z_Num++;
		/*-----------调试阶段--------------*/
		if (Teach_Status_flag)
		{
			if (Z_IT_Num == Z_Num)
			{
				Z_Num = 0;
				Z_Stop();
			}
		}
		/*----------运行阶段--------------*/
		else if(Run_status_flag)
		{
			if (Z_Num <= 1000 )
			{
				Z_Set_Autorelaod( Z_Accel_Freq[ Z_Num-1])
			}
			else if (Z_Num >= (Z_IT_Num - 1000) && Z_Num < Z_IT_Num)
					{
						Z_Decel_Num--;
						Z_Set_AutoReload( Z_Accel_Freq[ Z_Decel_Num ]);
						if (Z_Decel_Num == 0)Z_Decel_Num = 1000;
					}
		  else if(Z_Num >= Z_IT_Num)
					 {
						 Z_Num = 0;
						 Z_Stop();

						 if ( Z_IT_point == Z_run_point )
						 {
							 if (max_run_point >= Z_run_point)
							 Z_run_point =1;
							 Z_IT_point  =1;
							 main_flag =1;
							 else
							 Z_run_point ++;
							 Z_IT_point ++;
							 main_flag = 1;
						 }	 
					 }		 
		}		
	}
	
	
	
}