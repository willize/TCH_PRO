#include "Arm_control.h"
#include "Motor_Control.h"
#include "TIM.h"
#include "delay.h"


#define  Z_SUBDIVISION  800                 //��������ϸ���� 
float  PULSES = (360/Z_SUBDIVISION);   //һ�������Ӧ�ĽǶ�

#define XY_SUBDIVISION  10000
float  XY_PULSES = (360/Z_SUBDIVISION); 

TI_num TIunm;
u8 num=1;

void Arm_Init(void)
{
	Motor_Init();
	if (num==1)
	{
		xy_Set_speed(2500);
		z_Set_speed(1250);
		num++;
	}else
	{
		xy_Set_speed(2500);
		z_Set_speed(1500);
	}
	X_R_MOV();
	Y_L_MOV();
	Z_UP_MOV();
	
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
	

	
//	xyz_Distance(1000);
//xyz_Set_speed(5000);
	
//	x_Set_speed(2500);  //800Hz 400Hz  200Hz 1MHZ/800Hz=1250, 1M/400=2500,1M/200=5000
	//x_Distance(1000);
	
	
	
	//while (HAL_GPIO_ReadPin(GPIOE,X_L_Limit_Pin|X_R_Limit_Pin);
	
}


//�ٶȵĵ�λ��s/r���Ƕȵĵ�λ����
void Arm_Control(float Xspeed, float Xangle, float Yspeed, float Yangle, float Zspeed, float Zhigh) 
{
	
	float X_pulse_time, Y_pulse_time, Z_pulse_time;
//	float	X_pulse_num, Y_pulse_num, Z_pulse_num;
	float X_Hz, Y_Hz, Z_Hz;
	float	X_Time, Y_Time, Z_Time; 
	TIunm.X_TInum=TIunm.Y_TInum=TIunm.Z_TInum=0;
	
	X_Hz = Z_SUBDIVISION / Xspeed;   //һȦ�������� �൱��Ƶ��
	X_pulse_time = 1000.0f / X_Hz * 1000.0f;//һ�������ʱ��  ��λ��us
	//X_pulse_num = Xangle / PULSES; //��ת�Ƕȶ�Ӧ��������
	//X_Time = X_pulse_num * ( X_pulse_time / 1000.0f ) + 0.5f;  //��ת�Ƕȶ�Ӧ��ʱ��
	X_Time = Xspeed * 1000.0f / 360 * Xangle + 0.5f;
	
  x_Set_speed((u32)X_pulse_time );//
	TIunm.X_TInum = (int) X_Time;
	
	Y_Hz = XY_SUBDIVISION / Yspeed;   //һȦ�������� �൱��Ƶ��
	Y_pulse_time = 1000.0f / Y_Hz *1000.0f;//һ�������ʱ��  ��λ��us
	//Y_pulse_num = Yangle / PULSES; //��ת�Ƕȶ�Ӧ��������
	//Y_Time = Y_pulse_num * ( Y_pulse_time / 1000.0f ) + 0.5f;  //��ת�Ƕȶ�Ӧ��ʱ��
	Y_Time = Yspeed * 1000.0f / 360 * Yangle + 0.5f;
	
  y_Set_speed((u32)Y_pulse_time );//
	TIunm.Y_TInum = (int)Y_Time;
	
	
	Z_Hz = XY_SUBDIVISION / Zspeed;   //һȦ�������� �൱��Ƶ��
	Z_pulse_time = 1000.0f / Z_Hz *1000.0f;//һ�������ʱ��  ��λ��us
	//Z_pulse_num = (Zhigh*360.0f) / PULSES; //��ת�Ƕȶ�Ӧ��������
	//Z_Time = Z_pulse_num * ( Z_pulse_time / 1000.0f ) + 0.5f;  //��ת�Ƕȶ�Ӧ��ʱ��
	Z_Time = Zspeed * 1000.0f / 360 * (Zhigh*360.0f) + 0.5f;
	
  z_Set_speed((u32)Z_pulse_time );//
	TIunm.Z_TInum = (int)Z_Time;
	
	printf("X_time:%f\n Y_time:%f\n Z_time:%f\r\n ",X_Time,Y_Time,Z_Time);
	printf("X_time:%d\n Y_time:%d\n Z_time:%d\r\n ",TIunm.X_TInum,TIunm.Y_TInum,TIunm.Z_TInum);
//	xyz_Distance(1000);  
	//__HAL_TIM_ENABLE(&htim5);
	//__HAL_TIM_ENABLE(&htim6);
//	__HAL_TIM_ENABLE(&htim7);
	HAL_TIM_Base_Start_IT(&htim5);
	HAL_TIM_Base_Start_IT(&htim6);
	HAL_TIM_Base_Start_IT(&htim7);
	
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
	
}

void X_Control(float Xangle)
{
	//	float X_pulse_time;
//	float	X_pulse_num, Y_pulse_num, Z_pulse_num;
	//float X_Hz;
	//float	X_Time; 
	float X_Pwm_Num;
	
	//X_Hz = SUBDIVISION / Xspeed;   //һȦ�������� �൱��Ƶ��
	//X_pulse_time = 1000.0f / X_Hz * 1000.0f;//һ�������ʱ��  ��λ��us
	//X_pulse_num = Xangle / PULSES; //��ת�Ƕȶ�Ӧ��������
	//X_Time = X_pulse_num * ( X_pulse_time / 1000.0f ) + 0.5f;  //��ת�Ƕȶ�Ӧ��ʱ��
	//X_Time = Xspeed * 1000.0f / 360 * Xangle + 0.5f;
	X_Pwm_Num= Xangle * 12.0f / 0.45f +0.5f;
	
  x_Set_speed(7000 );
	TIunm.X_TInum = (u32) X_Pwm_Num;

	__HAL_TIM_ENABLE(&htim4);
	HAL_TIM_Base_Start_IT(&htim4);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
	
}

void Y_Control( float Yangle)  //���800����
{
//float Y_pulse_time;
//	float	X_pulse_num, Y_pulse_num, Z_pulse_num;
//	float Y_Hz;
//float	Y_Time; 
	float Y_Pwm_Num;
	
	
 // Y_Hz = SUBDIVISION / Yspeed;   //һȦ�������� �൱��Ƶ��
//	Y_pulse_time = 1000.0f / Y_Hz *1000.0f;//һ�������ʱ��  ��λ��us
//	Y_pulse_num = Yangle / PULSES; //��ת�Ƕȶ�Ӧ��������
	//Y_Time = Y_pulse_num * ( Y_pulse_time / 1000.0f ) + 0.5f;  //��ת�Ƕȶ�Ӧ��ʱ��
//	Y_Time = Yspeed * 1000.0f / 360 * Yangle + 0.5f;
	
	Y_Pwm_Num = Yangle * 12.0f / 0.45f +0.5 ;//1/10000  0.036Ϊһ������ĽǶ�
	
  y_Set_speed(8000 );//
	TIunm.Y_TInum = (u32)Y_Pwm_Num;

	__HAL_TIM_ENABLE(&htim3);
	HAL_TIM_Base_Start_IT(&htim3);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	
	
	
	
}


void Z_Control(float Zhigh)
{
	//float Z_pulse_time;
  //float	X_pulse_num, Y_pulse_num, Z_pulse_num;
	//float Z_Hz;
	//float	Z_Time;
	u16 Pwm_Num;
	
	//Z_Hz = SUBDIVISION / Zspeed;   //һȦ�������� �൱��Ƶ��
	//Z_pulse_time = 1000.0f / Z_Hz *1000.0f;//һ�������ʱ��  ��λ��us
	//Z_pulse_num = (Zhigh*360.0f) / PULSES; //��ת�Ƕȶ�Ӧ��������
	//Z_Time = Z_pulse_num * ( Z_pulse_time / 1000.0f ) + 0.5f;  //��ת�Ƕȶ�Ӧ��ʱ��
  //Z_Time = Zspeed * 1000.0f / 360 * (Zhigh*360.0f) + 0.5f;
	
	Pwm_Num= Zhigh * 800; 
  z_Set_speed(6250);//
	TIunm.Z_TInum = Pwm_Num;
	
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	__HAL_TIM_ENABLE(&htim2);
	HAL_TIM_Base_Start_IT(&htim2);
	

	
}






