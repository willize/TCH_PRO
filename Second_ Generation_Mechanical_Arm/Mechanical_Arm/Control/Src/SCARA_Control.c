#include "SCARA_Control.h"
#include "delay.h"
#include "SCARA_Alg.h"

float Z_Accel_Freq[1000],XY_Accel_Freq[100];
u16   Z_Accel_Period[100],XY_Accel_Period[100];
float Dist[3];            //����Ҫ���еľ��� ��flash�л�ȡ
s8 Dire[3];               //�����˶��ķ���

u8 X_run_point,Y_run_point,Z_run_point;
u8 max_run_point ;
u8 main_flag;
volatile u8 Point_Num;                   

void Mechaical_Arm_Init()
{
	
	
	
	
	
}

void MechaArm_Run_Point_contr()//��е�����е�λ����
{
	delay_ms(500);
	if (X_run_point == Point_Num && Y_run_point == Point_Num && Z_run_point == Point_Num)
	{
		if (main_flag == 1)
		{
			SCARA_Control(Dist,Dire);
			Point_Num++;
			main_flag = 0;
		}
	}
}

