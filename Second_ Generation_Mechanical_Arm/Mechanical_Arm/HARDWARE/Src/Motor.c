#include "Motor.h"
#include "main.h"
#include "pwm.h"

extern TIM_HandleTypeDef htim10;
extern TIM_HandleTypeDef htim11;
extern TIM_HandleTypeDef htim13;

 u16 X_IT_Num, Y_IT_Num, Z_IT_Num; //各轴电机移动的步数 在中断中的个数

void Motor_Dir_GPIO_Init()
{
		GPIO_InitTypeDef GPIO_Initure;
	__HAL_RCC_GPIOD_CLK_ENABLE();           //开启GPIOB时钟

	GPIO_Initure.Pin= X_DIR_PIN| Y_DIR_PIN| Z_DIR_PIN; //PB1,0
	GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  //推挽输出
	GPIO_Initure.Pull=GPIO_PULLUP;          //上拉
	GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //高速
	HAL_GPIO_Init(X_DIR_GPIO,&GPIO_Initure);
}
/*---------------------------设置预装载值------------------------------*/
void X_Set_AutoReload(u16 AutoReload)
{
	__HAL_TIM_SET_AUTORELOAD(&htim10, AutoReload);
	__HAL_TIM_SET_COMPARE(&htim10,TIM_CHANNEL_1, AutoReload/2);
}

void Y_Set_AutoReload(u16 AutoReload)
{
	__HAL_TIM_SET_AUTORELOAD(&htim11, AutoReload);
	__HAL_TIM_SET_COMPARE(&htim11,TIM_CHANNEL_1, AutoReload/2);
}

void Z_Set_AutoReload(u16 AutoReload)
{
	__HAL_TIM_SET_AUTORELOAD(&htim13, AutoReload);
	__HAL_TIM_SET_COMPARE(&htim13,TIM_CHANNEL_1, AutoReload/2);
}
/***********************************************************************/


/*---------------------------设置电机速度------------------------------*/
void X_Set_Speed(float speed)//单位 r/s
{
	u16 AutoReload=0;
	float Pulses=0.0f;
	Pulses= speed * XY_SUBDIVISION;
	AutoReload =(u16) 10000 / Pulses *100;
	__HAL_TIM_SET_AUTORELOAD(&htim10, AutoReload);
	__HAL_TIM_SET_COMPARE(&htim10,TIM_CHANNEL_1, AutoReload/2);
}

void Y_Set_Speed(float speed)
{
	u16 AutoReload=0;
	float Pulses=0.0f;
	Pulses= speed * XY_SUBDIVISION;
	printf("Y轴输出脉冲个数：%f\r\n",Pulses);
	AutoReload =(u16) 10000 / Pulses *100;
	printf("输出Y轴自动装载值：%d\r\n",AutoReload);
	__HAL_TIM_SET_AUTORELOAD(&htim11, AutoReload);
	__HAL_TIM_SET_COMPARE(&htim11,TIM_CHANNEL_1, AutoReload/2);
}

void Z_Set_Speed(float speed)
{
	u16 AutoReload=0;
	float Pulses=0.0f;
	Pulses= speed * Z_SUBDIVISION;
		printf("z轴输出脉冲个数：%f",Pulses);
	AutoReload =(u16) 1000 / Pulses *1000;
	printf("输出z轴自动装载值：%d",AutoReload);
	__HAL_TIM_SET_AUTORELOAD(&htim13, AutoReload);
	__HAL_TIM_SET_COMPARE(&htim13,TIM_CHANNEL_1, AutoReload/2);
}

void XY_Set_Speed(float X_speed,float Y_speed )
{
	u16 X_AutoReload = 0,Y_AutoReload = 0;
	float X_Pulses, Y_Pulses;
	X_Pulses= X_speed * XY_SUBDIVISION;
	Y_Pulses= Y_speed * XY_SUBDIVISION;
	X_AutoReload = 10000 /X_Pulses *100;
	Y_AutoReload = 10000 /Y_Pulses *100;
	__HAL_TIM_SET_AUTORELOAD(&htim10, X_AutoReload);
	__HAL_TIM_SET_COMPARE(&htim10,TIM_CHANNEL_1, X_AutoReload/2);
	__HAL_TIM_SET_AUTORELOAD(&htim11, Y_AutoReload);
	__HAL_TIM_SET_COMPARE(&htim11,TIM_CHANNEL_1, Y_AutoReload/2);		
}

void XZ_Set_Speed(float X_speed,float Z_speed )
{
	u16 X_AutoReload = 0,Z_AutoReload = 0;
	float X_Pulses, Z_Pulses;
	X_Pulses= X_speed * XY_SUBDIVISION;
	Z_Pulses= Z_speed * Z_SUBDIVISION;
	X_AutoReload = 10000 /X_Pulses *100;
	Z_AutoReload = 10000 /Z_Pulses *100;
	__HAL_TIM_SET_AUTORELOAD(&htim10, X_AutoReload);
	__HAL_TIM_SET_COMPARE(&htim10,TIM_CHANNEL_1, X_speed/2);
	__HAL_TIM_SET_AUTORELOAD(&htim13, Z_AutoReload);
	__HAL_TIM_SET_COMPARE(&htim13,TIM_CHANNEL_1, Z_speed/2);		
}

void YZ_Set_Speed(float Y_speed,float Z_speed )
{
	u16 Y_AutoReload = 0,Z_AutoReload = 0;
	float Y_Pulses, Z_Pulses;
	Y_Pulses= Y_speed * XY_SUBDIVISION;
	Z_Pulses= Z_speed * Z_SUBDIVISION;
	Y_AutoReload = 10000 /Y_Pulses *100;
	Z_AutoReload = 10000 /Z_Pulses *100;
	__HAL_TIM_SET_AUTORELOAD(&htim11, Y_AutoReload);
	__HAL_TIM_SET_COMPARE(&htim11,TIM_CHANNEL_1, Y_speed/2);
	__HAL_TIM_SET_AUTORELOAD(&htim13, Z_AutoReload);
	__HAL_TIM_SET_COMPARE(&htim13,TIM_CHANNEL_1, Z_speed/2);		
}

void XYZ_Set_Speeed(float X_speed , float Y_speed, float Z_speed )
{
	u16 X_AutoReload = 0,Y_AutoReload = 0,Z_AutoReload = 0;
	float X_Pulses, Y_Pulses, Z_Pulses;
	X_Pulses= X_speed * XY_SUBDIVISION;
	Y_Pulses= Y_speed * XY_SUBDIVISION;
	Z_Pulses= Z_speed * Z_SUBDIVISION;
	X_AutoReload = 10000 /X_Pulses *100;
	Y_AutoReload = 10000 /Y_Pulses *100;
	Z_AutoReload = 10000 /Z_Pulses *100;
	__HAL_TIM_SET_AUTORELOAD(&htim10, X_AutoReload);
	__HAL_TIM_SET_COMPARE(&htim10,TIM_CHANNEL_1, X_speed/2);
	__HAL_TIM_SET_AUTORELOAD(&htim11, Y_AutoReload);
	__HAL_TIM_SET_COMPARE(&htim11,TIM_CHANNEL_1, Y_speed/2);
	__HAL_TIM_SET_AUTORELOAD(&htim13, Z_AutoReload);
	__HAL_TIM_SET_COMPARE(&htim13,TIM_CHANNEL_1, Z_speed/2);
}
/*************************************************************/

/*-------------------------电机移动距离----------------------*/
void X_Move_Angle(float Xangle)
{
	float X_PWM_Num;
	X_PWM_Num = Xangle * REDUCTION_RATIO / One_Pulse_Agle + 0.5f;
  X_IT_Num = (u16) X_PWM_Num;
}

void Y_Move_Angle(float Yangle)
{
	float Y_PWM_Num;
	Y_PWM_Num = Yangle * REDUCTION_RATIO / One_Pulse_Agle + 0.5f;
  Y_IT_Num = (u16) Y_PWM_Num;
}

void Z_Move_High(float Zhigh)
{
	float Z_PWM_Num;
	Z_PWM_Num = Zhigh * Z_SUBDIVISION;
  Z_IT_Num = (u16) Z_PWM_Num;
	printf("中断次数为：%d\r\n",Z_IT_Num);
}
/********************************************************************/

/*-----------------------电机移动的开始、停止-----------------------*/
void X_Start()
{
	__HAL_TIM_ENABLE(&htim10);
	HAL_TIM_Base_Start_IT(&htim10);
	HAL_TIM_PWM_Start(&htim10,TIM_CHANNEL_1);
}

void Y_Start()
{
	__HAL_TIM_ENABLE(&htim11);
	HAL_TIM_Base_Start_IT(&htim11);
	HAL_TIM_PWM_Start(&htim11,TIM_CHANNEL_1);
}

void Z_Start()
{
	__HAL_TIM_ENABLE(&htim13);
	HAL_TIM_Base_Start_IT(&htim13);
	HAL_TIM_PWM_Start(&htim13,TIM_CHANNEL_1);
}

void X_Stop()
{
	HAL_TIM_Base_Stop_IT(&htim10);
	HAL_TIM_PWM_Stop(&htim10,TIM_CHANNEL_1);
}
void Y_Stop()
{
	HAL_TIM_Base_Stop_IT(&htim11);
	HAL_TIM_PWM_Stop(&htim11,TIM_CHANNEL_1);
}
void Z_Stop()
{
	HAL_TIM_Base_Stop_IT(&htim13);
	HAL_TIM_PWM_Stop(&htim13,TIM_CHANNEL_1);
}

void XYZ_Stop()
{
	HAL_TIM_Base_Stop_IT(&htim10);
	HAL_TIM_PWM_Stop(&htim10,TIM_CHANNEL_1);
	HAL_TIM_Base_Stop_IT(&htim11);
	HAL_TIM_PWM_Stop(&htim11,TIM_CHANNEL_1);
	HAL_TIM_Base_Stop_IT(&htim13);
	HAL_TIM_PWM_Stop(&htim13,TIM_CHANNEL_1);
}

/*************************************************************************/


