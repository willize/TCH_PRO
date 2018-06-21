#include "Motor_Control.h"
#include "TIM.h"

void Motor_Init()  // 初始化电机
{
/************step motor pwm init*************/
  MX_TIM2_Init(83, 0);
  MX_TIM3_Init(83, 0);
  MX_TIM4_Init(83, 0);
/************step motor tim init*************/	
  MX_TIM5_Init(8399, 10000);
  MX_TIM6_Init(83, 1000);
  MX_TIM7_Init(83, 1000);
	
}


/**************设置电机速度******************/
void xyz_Set_speed(u16 speed) 
{
	
	__HAL_TIM_SET_AUTORELOAD(&htim2, speed);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, speed/2);
	__HAL_TIM_SET_AUTORELOAD(&htim3, speed);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, speed/2);
	__HAL_TIM_SET_AUTORELOAD(&htim4, speed);
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, speed/2);
	
}

void xy_Set_speed(u16 speed)
{
	__HAL_TIM_SET_AUTORELOAD(&htim3, speed);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, speed/2);
	__HAL_TIM_SET_AUTORELOAD(&htim4, speed);
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, speed/2);
}

void x_Set_speed(u16 speed)
{
	__HAL_TIM_SET_AUTORELOAD(&htim4, speed);
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, speed/2);
}

void y_Set_speed(u16 speed)
{
	__HAL_TIM_SET_AUTORELOAD(&htim3, speed);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, speed/2);
}

void z_Set_speed(u16 speed)
{
  __HAL_TIM_SET_AUTORELOAD(&htim2, speed);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, speed/2);
}

/**********************************************/

/**************设置电机运行距离****************/
void xyz_Distance(u16 length)
{
	__HAL_TIM_SET_AUTORELOAD(&htim5, length);
	__HAL_TIM_SET_AUTORELOAD(&htim6, length);
	__HAL_TIM_SET_AUTORELOAD(&htim7, length);
}

void xy_Distance(u16 length)
{
	__HAL_TIM_SET_AUTORELOAD(&htim6, length);
	__HAL_TIM_SET_AUTORELOAD(&htim7, length);
}
void x_Distance(u16 length)
{
	__HAL_TIM_SET_AUTORELOAD(&htim7, length);
}
void y_Distance(u16 length)
{
	
	__HAL_TIM_SET_AUTORELOAD(&htim6, length);
	
}
void z_Distance(u16 length)
{
	__HAL_TIM_SET_AUTORELOAD(&htim5, length);

}

/***********************************************/


