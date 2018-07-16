#include "SCARA_Control.h"
#include "delay.h"
#include "SCARA_Alg.h"
#include "S_algorithm.h"
#include "Motor.h"
#include "pwm.h"

float   Z_Accel_Freq[1000],XY_Accel_Freq[100];
u16   Z_Accel_Period[1000],XY_Accel_Period[100];
float Dist[3];            //����Ҫ���еľ��� ��flash�л�ȡ
s8 Dire[3];               //�����˶��ķ���

u8 X_run_point,Y_run_point,Z_run_point;
u8 max_run_point =200;
u8 main_flag;
volatile u8 Point_Num;                   

void Mechaical_Arm_Init()
{
	
	Motor_Dir_GPIO_Init();
		
	X_PWM_Init(83, 0);
	Y_PWM_Init(83, 0);
	Z_PWM_Init(83, 0);
	CalaculateSModel_Accel(Z_Accel_Freq, Z_Accel_Period, 1000, 3200, 200, 4);
	Motor_Max_Speed();
	
	
}

u16 MechaArm_Run_Point_contr()//��е�����е�λ����
{
	static u16 i ,init;
	delay_ms(500);
	if(init == 1)        //�ж��Ƿ���Ҫ��ʼ����Ҳ���ǻ�е���Ѿ����˳�ʼλ��
	{
		Mechaical_Arm_Init();
		init = 0;
	}
	else if (X_run_point == Point_Num && Y_run_point == Point_Num && Z_run_point == Point_Num) //���е�
	{
		if (main_flag == 1)
		{
			SCARA_Control(Dist+i,Dire+i);
			i+=3;                        //��ȡ�ƶ��������������
			Point_Num++;
			main_flag = 0;
			if ( max_run_point == main_flag ) 
			{
				init=1;
				return init;
			}
		}
	}
	return 1;
}

