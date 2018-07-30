#include "SCARA_Control.h"
#include "delay.h"
#include "SCARA_Alg.h"
#include "S_algorithm.h"
#include "Motor.h"
#include "pwm.h"
#include "main.h"

float   Z_Accel_Freq[1000],XY_Accel_Freq[100];
u16   Z_Accel_Period[1000],XY_Accel_Period[100];
//float Dist[3];            //����Ҫ���еľ��� ��flash�л�ȡ
//s8 Dire[3];               //�����˶��ķ���

float Dist[3][100];

u8 X_run_point,Y_run_point,Z_run_point;
u8 max_run_point =0;
u8 main_flag;
volatile u8 Point_Num=0;                   

extern Odometer Teach_Odom;

void Mechaical_Arm_Init()
{
	
	Motor_Dir_GPIO_Init();
		
	X_PWM_Init(83, 0);
	Y_PWM_Init(83, 0);
	Z_PWM_Init(83, 0);
	CalaculateSModel_Accel(Z_Accel_Freq, Z_Accel_Period, 1000, 3200, 200, 4);
	Motor_Max_Speed();
	Teach_Odom.X_Odom=0;
	Teach_Odom.Y_Odom=0;
	Teach_Odom.Z_Odom=0;
	X_run_point=0;
	Y_run_point=0;
	Z_run_point=0;
	
}

u16 MechaArm_Run_Point_contr()//��е�����е�λ����
{
	static u16 buf_i ,init;
	delay_ms(500);
	if(init == 1)        //�ж��Ƿ���Ҫ��ʼ����Ҳ���ǻ�е���Ѿ����˳�ʼλ��
	{
		Mechaical_Arm_Init();
		init = 0;
	}
	else if ((X_run_point == Point_Num) && (Y_run_point == Point_Num) && (Z_run_point == Point_Num)) //���е�
	{
		if (main_flag == 1)
		{
			SCARA_Control(downl_x.Dist+buf_i,downl_y.Dist+buf_i,downl_z.Dist+buf_i);
			buf_i+=1;                        //��ȡ�ƶ��������������
			Point_Num++;
			main_flag = 0;
			if ( max_run_point == main_flag ) 
			{
				init=1;
				buf_i=0;
				return init;
			}
		}
	}
	return buf_i;
}

